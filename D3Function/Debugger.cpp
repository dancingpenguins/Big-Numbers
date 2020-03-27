#include "stdafx.h"

#ifdef DEBUG_POLYGONIZER

#include <Thread.h>
#include "DebugIsoSurface.h"
#include "Mainfrm.h"
#include "Debugger.h"

Debugger::Debugger(D3SceneContainer *sc, const IsoSurfaceParameters &param)
: m_flags(FL_BREAKONNEXTFACE)
, m_state(DEBUGGER_CREATED)
{
  m_surface = new DebugIsoSurface(this,*sc,param); TRACE_NEW(m_surface);
}

Debugger::~Debugger() {
  kill();
  SAFEDELETE(m_surface);
}

void Debugger::singleStep(BYTE breakFlags) {
  checkTerminated().clrFlag(FL_ALLBREAKFLAGS).setFlag(breakFlags).resume();
}

void Debugger::kill() {
  setInterrupted();
  waitUntilJobDone();
  setProperty(DEBUGGER_STATE, m_state, DEBUGGER_TERMINATED);
}

UINT Debugger::safeRun() {
  SETTHREADDESCRIPTION("Debugger");
  setProperty(DEBUGGER_STATE, m_state, DEBUGGER_RUNNING);
  suspend();
  m_surface->createData();
  setProperty(DEBUGGER_STATE, m_state, DEBUGGER_TERMINATED);
  return 0;
}

void Debugger::suspend() {
  setProperty(DEBUGGER_STATE, m_state, DEBUGGER_PAUSED);
  __super::suspend();
  setProperty(DEBUGGER_STATE, m_state, DEBUGGER_RUNNING);
}

void Debugger::handleStep(StepType type) {
  if(isInterruptedOrSuspended()) {
    if(isInterrupted()) {
      die();
    } else if(isSuspended()) {
      suspend();
      return;
    }
  }
  if(m_flags) {
    switch(type) {
    case NEW_LEVEL:
      if(isSet(FL_ALLBREAKFLAGS)) {
        m_surface->updateSceneObject(MESH_VISIBLE | OCTA_VISIBLE);
        suspend();
      }
      break;
    case NEW_OCTA:
      if(isSet(FL_BREAKONNEXTOCTA)) {
        m_surface->updateSceneObject(MESH_VISIBLE | OCTA_VISIBLE);
        suspend();
      }
      break;
    case NEW_TETRA:
      if(isSet(FL_BREAKONNEXTTETRA)) {
        m_surface->updateSceneObject(MESH_VISIBLE | OCTA_VISIBLE | TETRA_VISIBLE);
        suspend();
      }
      break;
    case NEW_FACE :
      if(isSet(FL_BREAKONNEXTFACE | FL_BREAKONNEXTVERTEX)) {
        m_surface->updateSceneObject(MESH_VISIBLE | OCTA_VISIBLE | TETRA_VISIBLE | FACES_VISIBLE | VERTEX_VISIBLE);
        suspend();
      }
      break;
    case NEW_VERTEX:
      if(isSet(FL_BREAKONNEXTVERTEX)) {
        m_surface->updateSceneObject(MESH_VISIBLE | OCTA_VISIBLE | TETRA_VISIBLE | FACES_VISIBLE | VERTEX_VISIBLE);
        suspend();
      }
      break;
    }
  }
}

D3SceneObjectVisual *Debugger::getSceneObject() {
  return m_surface->getSceneObject();
}

String Debugger::getFlagNames(BYTE flags) { // static
  const TCHAR *delim = NULL;
  String result;
#define ADDFLAG(f) if(flags & (FL_##f)) { if(delim) result += delim; else delim = _T(" "); result += _T(#f); }
  ADDFLAG(BREAKONNEXTLEVEL )
  ADDFLAG(BREAKONNEXTOCTA  )
  ADDFLAG(BREAKONNEXTTETRA )
  ADDFLAG(BREAKONNEXTFACE  )
  ADDFLAG(BREAKONNEXTVERTEX)
  return result;
#undef ADDFLAG
}

String Debugger::getStateName(DebuggerState state) { // static
#define CASESTR(s) case DEBUGGER_##s: return _T(#s)
  switch(state) {
  CASESTR(CREATED   );
  CASESTR(RUNNING   );
  CASESTR(PAUSED    );
  CASESTR(TERMINATED);
  default: return format(_T("Unknown debuggerState:%d"), state);
  }
#undef CASESTR
}

#endif // DEBUG_POLYGONIZER
