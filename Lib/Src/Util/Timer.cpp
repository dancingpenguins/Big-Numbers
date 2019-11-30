#include "pch.h"
#include <Timer.h>
#include <Semaphore.h>
#include <PropertyContainer.h>

#define KILLED                 0x01
#define REPEAT_TIMEOUT         0x02
#define HANDLER_ACTIVE         0x04
#define SETTIMEOUT_PENDING     0x08

#define ISKILLED()             (m_state & KILLED            )
#define ISREPEATTIMEOUT()      (m_state & REPEAT_TIMEOUT    )
#define ISHANDLERACTIVE()      (m_state & HANDLER_ACTIVE    )
#define ISSETTIMEOUT_PENDING() (m_state & SETTIMEOUT_PENDING)

class TimerThread : private Thread {
private:
  Timer          &m_timer;
  FastSemaphore   m_stateSem, m_terminated;
  Semaphore       m_timeout;
  BYTE            m_state;
  int             m_msec; // msec
  TimeoutHandler &m_handler;
  void setFlag(BYTE flag);
  void clrFlag(BYTE flag);
public:
  TimerThread(Timer *timer, int msec, TimeoutHandler &handler, bool repeatTimeout);
  ~TimerThread();
  UINT run();
  void kill();
  inline bool isKilled() const {
    return (m_state & KILLED) != 0;
  }
  void setTimeout(int msec, bool repeatTimeout);
  inline int getTimeout() const {
    return m_msec;
  }
};

TimerThread::TimerThread(Timer *timer, int msec, TimeoutHandler &handler, bool repeatTimeout)
: Thread(format(_T("Timerthread %d"), timer->getId()))
, m_timer(*timer)
, m_msec(msec)
, m_handler(handler)
, m_timeout(0)
, m_terminated(0)
{
  m_state = repeatTimeout ? REPEAT_TIMEOUT : 0;
  resume();
}

TimerThread::~TimerThread() {
  kill();
  m_terminated.wait();
}

void TimerThread::kill() {
  setFlag(KILLED);
  if(!ISHANDLERACTIVE()) {
    m_timeout.notify();
  }
}

void TimerThread::setTimeout(int msec, bool repeatTimeout) {
  m_stateSem.wait();

  if(repeatTimeout) {
    m_state |= REPEAT_TIMEOUT;
  } else {
    m_state &= ~REPEAT_TIMEOUT;
  }
  m_msec = msec;
  if(!ISHANDLERACTIVE()) {
    m_state |= SETTIMEOUT_PENDING;
    m_timeout.notify();
  }
  m_stateSem.notify();
}

void TimerThread::setFlag(BYTE flags) {
  m_stateSem.wait();
  m_state |=  flags;
  m_stateSem.notify();
}

void TimerThread::clrFlag(BYTE flags) {
  m_stateSem.wait();
  m_state &= ~flags;
  m_stateSem.notify();
}

UINT TimerThread::run() {
  while(!ISKILLED()) {
    m_timeout.wait(m_msec);

    if(ISKILLED()) {
      break;
    }
    if(ISSETTIMEOUT_PENDING()) {
      clrFlag(SETTIMEOUT_PENDING);
      continue;
    }
    setFlag(HANDLER_ACTIVE);
    m_handler.handleTimeout(m_timer);
    clrFlag(HANDLER_ACTIVE);

    if(!ISREPEATTIMEOUT()) {
      setFlag(KILLED);
    }
  }
  m_terminated.notify();
  return 0;
}

Timer::Timer(int id) : m_id(id), m_blockStart(false) {
  m_thread = NULL;
}

Timer::~Timer() {
  stopTimer();
  destroyThread();
}

void Timer::createThread(int msec, TimeoutHandler &handler, bool repeatTimeout) {
  m_thread = new TimerThread(this, msec, handler, repeatTimeout); TRACE_NEW(m_thread);
  Thread::addPropertyChangeListener(this);
}

void Timer::destroyThread() {
  if(m_thread) {
    SAFEDELETE(m_thread);
    Thread::removePropertyChangeListener(this);
  }
}

void Timer::startTimer(int msec, TimeoutHandler &handler, bool repeatTimeout) {
  m_gate.wait();
  if(!m_blockStart) {
    if(m_thread == NULL || m_thread->isKilled()) {
      destroyThread();
      createThread(msec, handler, repeatTimeout);
    }
  }
  m_gate.notify();
}

void Timer::stopTimer() {
  m_gate.wait();
  if(m_thread) {
    m_thread->kill();
  }
  m_gate.notify();
}

bool Timer::isRunning() const {
  m_gate.wait();
  const bool result = m_thread && !m_thread->isKilled();
  m_gate.notify();
  return result;
}

int Timer::getTimeout() const {
  m_gate.wait();
  const int result = m_thread ? m_thread->getTimeout() : 0;
  m_gate.notify();
  return result;
}

void Timer::setTimeout(int msec, bool repeatTimeout) {
  m_gate.wait();
  if(m_thread && !m_thread->isKilled()) {
    m_thread->setTimeout(msec, repeatTimeout);
  }
  m_gate.notify();
}

void Timer::handlePropertyChanged(const PropertyContainer *source, int id, const void *oldValue, const void *newValue) {
  if(Thread::isPropertyContainer(source) && (id == THR_SHUTTINGDDOWN)) {
    m_blockStart = true;
    stopTimer();
    destroyThread();
  }
}
