/* DO NOT EDIT THIS FILE - it is machine generated */
#line 16 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
#include "stdafx.h"
#include "Olm641Symbol.h"
#include "Olm641Lex.h"


#line 8 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"


// The lexCharMap[] and lexStateMap arrays are used as follows:
//
// nextState = lexNext[lexStateMap[currentState]][lexCharMap[inputChar]];
//
// Character positions in the lexCharMap Array are:
//
//  \x00 \x01 \x02 \x03 \x04 \x05 \x06 \x07 \b   \t   \n   \x0b \f   \r   \x0e \x0f
//  \x10 \x11 \x12 \x13 \x14 \x15 \x16 \x17 \x18 \x19 \x1a \x1b \x1c \x1d \x1e \x1f
//  \s   !    "    #    $    %    &    \'   (    )    *    +    ,    -    .    /
//  0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
//  @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
//  P    Q    R    S    T    U    V    W    X    Y    Z    [    \\   ]    ^    _
//  `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
//  p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~    \x7f
//  \x80 \x81 \x82 \x83 \x84 \x85 \x86 \x87 \x88 \x89 \x8a \x8b \x8c \x8d \x8e \x8f
//  \x90 \x91 \x92 \x93 \x94 \x95 \x96 \x97 \x98 \x99 \x9a \x9b \x9c \x9d \x9e \x9f
//  \xa0 \xa1 \xa2 \xa3 \xa4 \xa5 \xa6 \xa7 \xa8 \xa9 \xaa \xab \xac \xad \xae \xaf
//  \xb0 \xb1 \xb2 \xb3 \xb4 \xb5 \xb6 \xb7 \xb8 \xb9 \xba \xbb \xbc \xbd \xbe \xbf
//  \xc0 \xc1 \xc2 \xc3 \xc4 \xc5 \xc6 \xc7 \xc8 \xc9 \xca \xcb \xcc \xcd \xce \xcf
//  \xd0 \xd1 \xd2 \xd3 \xd4 \xd5 \xd6 \xd7 \xd8 \xd9 \xda \xdb \xdc \xdd \xde \xdf
//  \xe0 \xe1 \xe2 \xe3 \xe4 \xe5 \xe6 \xe7 \xe8 \xe9 \xea \xeb \xec \xed \xee \xef
//  \xf0 \xf1 \xf2 \xf3 \xf4 \xf5 \xf6 \xf7 \xf8 \xf9 \xfa \xfb \xfc \xfd \xfe \xff

static unsigned char lexCharMap[256] = {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   2,   3,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       0,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   4,   5,   2,   6,   2,   7,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   8,   2,   9,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
       2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2
};

static const unsigned char lexStateMap[10] = {
    /*   0 */   0,   1,   2,   2,   2,   2,   2,   2,   2,   2
};

static const char lexNext[3][10] = {
    /*   0 */ { 1, 2,-1, 3, 4, 5, 6, 7, 8, 9},
    /*   1 */ { 1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   2 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

static const char lexAccept[] = {
    /*   0 */  0,  4,  4,  4,  4,  4,  4,  4,  4,  4
};

#line 11 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"

// nextState(state,c) is given the current state number and input
// character and evaluates to the next state.
#define nextState(state,c) (lexNext[lexStateMap[state]][lexCharMap[c]])

int Olm641Lex::getNextLexeme() {
  int  state           = 0;     // Current state
  int  lastAcceptState = 0;     // Most recently seen accept state
  int  prevState;               // State before lastAcceptState
  int  nextState;               // Next state
  unsigned int  lookahead;      // Lookahead character
  int  anchor;                  // Anchor mode for most recently seen accepting state

  unTerminateLexeme();
  initMore();
  markStart();

  for(;;) {
    // Check end of file. If there's an unprocessed accepting state,
    // lastAcceptState will be nonzero. In this case, ignore EOF for now so
    // that you can do the accepting action; otherwise, try to open another
    // file and return if you can't.

    for(;;) {
      if(((int)(lookahead = look(1))) != EOF) {
        assert(lookahead < 256);
        nextState = nextState(state, lookahead);
        break;
      } else if(lastAcceptState != 0) {   // still something to do
        nextState = -1;
        break;
      } else if(isWrap()) {               // another file?
        terminateLexeme();
        return 0;                         // EOI
      }
    }
    if(m_debug) {
      debugState(_T("--------"), state, lookahead);
    }

    if(nextState != -1) {
      if(advance() < 0) {                 // Buffer full
        const TCHAR *tooLongMessage = _T("Lexeme too long. Discarding extra characters.");
        error(getPos(), tooLongMessage);

        flush(true);

        if(m_debug) {
          debug(tooLongMessage);
          debugState(_T("--------"), state, look(1));
        }
      }

      if(anchor = lexAccept[nextState]) { // Is this an accept state
        prevState       = state;
        lastAcceptState = nextState;
        markEnd();                        // Mark input at current character
      }                                   // A subsequent gotoMark() returns us to this position.
      state = nextState;
    } else if(lastAcceptState == 0) {     // illegal input
      error(getPos(), _istprint(lookahead)?_T("Ignore bad input:'%c'"):_T("Ignore bad input:%#x"),lookahead);

      if(m_debug) {
        debug(_T("Ignore bad input:'%c'"), lookahead);
      }

      advance();
    } else {
      if(m_debug) {
        debugState(_T("accept--"), lastAcceptState, lookahead);
      }

      gotoMark();                         // Back up to previous accept state
      if(anchor & ANCHOR_END) {           // If end anchor is active
        pushback(1);                      // Push back the CR or LF
      }
      if(anchor & ANCHOR_START) {         // If start anchor is active
        moveStart();                      // Skip the leading newline
      }
      terminateLexeme();                  // Null-terminate the string

      switch(lastAcceptState) {
      case 1:
#line 36 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        ;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 2:
#line 34 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        ;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 3:
#line 35 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        ;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 4:
#line 28 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return a;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 5:
#line 29 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return b;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 6:
#line 30 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return d;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 7:
#line 31 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return f;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 8:
#line 33 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return x;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 9:
#line 32 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"
        return z;

#line 93 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;

      default:
        throwException(_T("%s:Unknown accept state:%d, text=<%s>"), __TFUNCTION__, lastAcceptState,getText());
        break;
      }

      unTerminateLexeme();
      lastAcceptState = 0;

      if(isMore()) {
        state = prevState;                // Back up
        initMore();
      } else {
        state = 0;
        markStart();
      }
    }
  }
}

#line 38 "C:\\mytools2015\\ParserGen\\Olm641\\Olm641.lex"

  /* This part goes to the last part of the cpp file */

#line 114 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
