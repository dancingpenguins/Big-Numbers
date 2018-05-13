/* DO NOT EDIT THIS FILE - it is machine generated */

#line 17 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
#include "stdafx.h"
#include <MyUtil.h>
#include <HashMap.h>
#include <TreeMap.h>
#include "Java5Symbol.h"
#include "Java5Lex.h"

static int nameOrKeyWord(const TCHAR *lexeme);

#line 9 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"

// DFA State   0 [nonAccepting]
//   goto  1 on \t\n\f\r\s
//   goto  2 on !
//   goto 57 on "
//   goto  3 on %
//   goto  4 on &
//   goto 60 on \'
//   goto  5 on (
//   goto  6 on )
//   goto  7 on *
//   goto  8 on +
//   goto  9 on ,
//   goto 10 on -
//   goto 11 on .
//   goto 12 on /
//   goto 13 on 0
//   goto 58 on 123456789
//   goto 14 on :
//   goto 15 on ;
//   goto 16 on <
//   goto 17 on =
//   goto 18 on >
//   goto 19 on ?
//   goto 20 on @
//   goto 21 on ABCDEFGHIJKLMNOPQRSTUVWXYZ
//   goto 22 on [
//   goto 23 on ]
//   goto 24 on ^
//   goto 21 on _abcdefghijklmnopqrstuvwxyz
//   goto 25 on {
//   goto 26 on |
//   goto 27 on }
//   goto 28 on ~
//   goto 21 on \x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95\x96\x97\x98
//              \x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae\xaf\xb0\xb1
//              \xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca
//              \xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0\xe1\xe2\xe3
//              \xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc
//              \xfd\xfe\xff
// DFA State   1 [accepting, line 124 <;>]
//   goto  1 on \t\n\f\r\s
// DFA State   2 [accepting, line  87 <return NOT;>]
//   goto 29 on =
// DFA State   3 [accepting, line 108 <return MOD;>]
//   goto 31 on =
// DFA State   4 [accepting, line 105 <return AND;>]
//   goto 32 on &
//   goto 33 on =
// DFA State   5 [accepting, line  75 <return LPAR;>]
// DFA State   6 [accepting, line  76 <return RPAR;>]
// DFA State   7 [accepting, line 103 <return STAR;>]
//   goto 34 on =
// DFA State   8 [accepting, line 101 <return PLUS;>]
//   goto 35 on +
//   goto 36 on =
// DFA State   9 [accepting, line  82 <return COMMA;>]
// DFA State  10 [accepting, line 102 <return MINUS;>]
//   goto 37 on -
//   goto 38 on =
// DFA State  11 [accepting, line  83 <return DOT;>]
//   goto 68 on .
//   goto 39 on 0123456789
// DFA State  12 [accepting, line 104 <return DIV;>]
//   goto 40 on *
//   goto 41 on /
//   goto 42 on =
// DFA State  13 [accepting, line  39 <return INTEGERLITERAL;>]
//   goto 39 on .
//   goto 61 on 0123456789
//   goto 59 on D
//   goto 69 on E
//   goto 59 on F
//   goto 64 on L
//   goto 70 on X
//   goto 59 on d
//   goto 69 on e
//   goto 59 on f
//   goto 64 on l
//   goto 70 on x
// DFA State  14 [accepting, line  90 <return COLON;>]
// DFA State  15 [accepting, line  81 <return SEMICOLON;>]
// DFA State  16 [accepting, line  85 <return LT;>]
//   goto 43 on <
//   goto 44 on =
// DFA State  17 [accepting, line  84 <return ASSIGN;>]
//   goto 45 on =
// DFA State  18 [accepting, line  86 <return GT;>]
//   goto 46 on =
//   goto 47 on >
// DFA State  19 [accepting, line  89 <return QUESTION;>]
// DFA State  20 [accepting, line  92 <return AT;>]
// DFA State  21 [accepting, line  48 <return nameOrKeyWord(getText());>]
//   goto 21 on 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\x80\x81\x82\x83\x84\x85\x86\x87\x88
//              \x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1
//              \xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae\xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba
//              \xbb\xbc\xbd\xbe\xbf\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3
//              \xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec
//              \xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff
// DFA State  22 [accepting, line  79 <return LB;>]
// DFA State  23 [accepting, line  80 <return RB;>]
// DFA State  24 [accepting, line 107 <return XOR;>]
//   goto 48 on =
// DFA State  25 [accepting, line  77 <return LC;>]
// DFA State  26 [accepting, line 106 <return OR;>]
//   goto 49 on =
//   goto 50 on |
// DFA State  27 [accepting, line  78 <return RC;>]
// DFA State  28 [accepting, line  88 <return COMPLEMENT;>]
// DFA State  29 [accepting, line  96 <return NEQ;>]
// DFA State  30 [accepting, line  43 <return STRINGLITERAL;>]
// DFA State  31 [accepting, line 119 <return MODASSIGN;>]
// DFA State  32 [accepting, line  97 <return ANDAND;>]
// DFA State  33 [accepting, line 116 <return ANDASSIGN;>]
// DFA State  34 [accepting, line 114 <return STARASSIGN;>]
// DFA State  35 [accepting, line  99 <return PLUSPLUS;>]
// DFA State  36 [accepting, line 112 <return PLUSASSIGN;>]
// DFA State  37 [accepting, line 100 <return MINUSMINUS;>]
// DFA State  38 [accepting, line 113 <return MINUSASSIGN;>]
// DFA State  39 [accepting, line  41 <return FLOATLITERAL;>]
//   goto 39 on 0123456789
//   goto 59 on D
//   goto 69 on E
//   goto 59 on Fd
//   goto 69 on e
//   goto 59 on f
// DFA State  40 [accepting, line  50 <{ int i;          SourcePosition startpos = getPos>]
// DFA State  41 [accepting, line  65 <{ int i;          while(i = input()) {            >]
// DFA State  42 [accepting, line 115 <return DIVASSIGN;>]
// DFA State  43 [accepting, line 109 <return SHL;>]
//   goto 53 on =
// DFA State  44 [accepting, line  94 <return LE;>]
// DFA State  45 [accepting, line  93 <return EQ;>]
// DFA State  46 [accepting, line  95 <return GE;>]
// DFA State  47 [accepting, line 110 <return SSHR;>]
//   goto 54 on =
//   goto 55 on >
// DFA State  48 [accepting, line 118 <return XORASSIGN;>]
// DFA State  49 [accepting, line 117 <return ORASSIGN;>]
// DFA State  50 [accepting, line  98 <return OROR;>]
// DFA State  51 [accepting, line  45 <return CHARACTERLITERAL;>]
// DFA State  52 [accepting, line  91 <return ELLIPSIS;>]
// DFA State  53 [accepting, line 120 <return SHLASSIGN;>]
// DFA State  54 [accepting, line 121 <return SSHRASSIGN;>]
// DFA State  55 [accepting, line 111 <return USHR;>]
//   goto 56 on =
// DFA State  56 [accepting, line 122 <return USHRASSIGN;>]
// DFA State  57 [nonAccepting]
//   goto 57 on \x00\x01\x02\x03\x04\x05\x06\x07\b\t\x0b\f\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c
//              \x1d\x1e\x1f\s!
//   goto 30 on "
//   goto 57 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[
//   goto 63 on \\
//   goto 57 on ]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7f\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f
//              \x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8
//              \xa9\xaa\xab\xac\xad\xae\xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1
//              \xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda
//              \xdb\xdc\xdd\xde\xdf\xe0\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3
//              \xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff
// DFA State  58 [accepting, line  39 <return INTEGERLITERAL;>]
//   goto 39 on .
//   goto 61 on 0123456789
//   goto 59 on D
//   goto 69 on E
//   goto 59 on F
//   goto 64 on L
//   goto 59 on d
//   goto 69 on e
//   goto 59 on f
//   goto 64 on l
// DFA State  59 [accepting, line  41 <return FLOATLITERAL;>]
// DFA State  60 [nonAccepting]
//   goto 65 on \x00\x01\x02\x03\x04\x05\x06\x07\b\t\x0b\f\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c
//              \x1d\x1e\x1f\s!"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[
//   goto 67 on \\
//   goto 65 on ]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7f\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f
//              \x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8
//              \xa9\xaa\xab\xac\xad\xae\xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1
//              \xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda
//              \xdb\xdc\xdd\xde\xdf\xe0\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3
//              \xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff
// DFA State  61 [accepting, line  39 <return INTEGERLITERAL;>]
//   goto 39 on .
//   goto 61 on 0123456789
//   goto 64 on Ll
// DFA State  62 [accepting, line  41 <return FLOATLITERAL;>]
//   goto 62 on 0123456789
//   goto 59 on DFdf
// DFA State  63 [nonAccepting]
//   goto 57 on \x00\x01\x02\x03\x04\x05\x06\x07\b\t\x0b\f\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c
//              \x1d\x1e\x1f\s!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuv
//              wxyz{|}~\x7f\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95
//              \x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae
//              \xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7
//              \xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0
//              \xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9
//              \xfa\xfb\xfc\xfd\xfe\xff
// DFA State  64 [accepting, line  39 <return INTEGERLITERAL;>]
// DFA State  65 [nonAccepting]
//   goto 51 on \'
// DFA State  66 [accepting, line  39 <return INTEGERLITERAL;>]
//   goto 66 on 0123456789ABCDEF
//   goto 64 on L
//   goto 66 on abcdef
//   goto 64 on l
// DFA State  67 [nonAccepting]
//   goto 65 on \x00\x01\x02\x03\x04\x05\x06\x07\b\t\x0b\f\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c
//              \x1d\x1e\x1f\s!"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuv
//              wxyz{|}~\x7f\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95
//              \x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae
//              \xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7
//              \xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0
//              \xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9
//              \xfa\xfb\xfc\xfd\xfe\xff
// DFA State  68 [nonAccepting]
//   goto 52 on .
// DFA State  69 [nonAccepting]
//   goto 71 on +-
//   goto 62 on 0123456789
// DFA State  70 [nonAccepting]
//   goto 66 on 0123456789ABCDEFabcdef
// DFA State  71 [nonAccepting]
//   goto 62 on 0123456789

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
       0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   2,   0,   1,   2,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       1,   3,   4,   0,   0,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,
      16,  17,  17,  17,  17,  17,  17,  17,  17,  17,  18,  19,  20,  21,  22,  23,
      24,  25,  25,  25,  26,  27,  26,  28,  28,  28,  28,  28,  29,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  30,  28,  28,  31,  32,  33,  34,  28,
       0,  25,  25,  25,  26,  27,  26,  28,  28,  28,  28,  28,  29,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  30,  28,  28,  35,  36,  37,  38,   0,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,
      28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28,  28
};

static const unsigned char lexStateMap[72] = {
    /*   0 */   0,   1,   2,   3,   4,   5,   5,   6,   7,   5,
    /*  10 */   8,   9,  10,  11,   5,   5,  12,  13,  14,   5,
    /*  20 */   5,  15,   5,   5,  16,   5,  17,   5,   5,   5,
    /*  30 */   5,   5,   5,   5,   5,   5,   5,   5,   5,  18,
    /*  40 */   5,   5,   5,  19,   5,   5,   5,  20,   5,   5,
    /*  50 */   5,   5,   5,   5,   5,  21,   5,  22,  23,   5,
    /*  60 */  24,  25,  26,  27,   5,  28,  29,  30,  31,  32,
    /*  70 */  33,  34
};

static const char lexNext[35][39] = {
    /*   0 */ {-1, 1, 1, 2,57, 3, 4,60, 5, 6, 7, 8, 9,10,11,12,13,58,14,15,16,17,18,19,20,21,21,21,21,21,21,22,-1,23,24,25,26,27,28},
    /*   1 */ {-1, 1, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   2 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   3 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   4 */ {-1,-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   5 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   6 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   7 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   8 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*   9 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,68,-1,39,39,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  10 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,40,-1,-1,-1,-1,41,-1,-1,-1,-1,-1,42,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  11 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,-1,61,61,-1,-1,-1,-1,-1,-1,-1,-1,59,69,-1,64,70,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  12 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  13 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  14 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,46,47,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  15 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,21,21,-1,-1,-1,-1,-1,-1,-1,21,21,21,21,21,21,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  16 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  17 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1},
    /*  18 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,39,-1,-1,-1,-1,-1,-1,-1,-1,59,69,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  19 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  20 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  21 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,56,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  22 */ {57,57,-1,57,30,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,63,57,57,57,57,57,57},
    /*  23 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,-1,61,61,-1,-1,-1,-1,-1,-1,-1,-1,59,69,-1,64,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  24 */ {65,65,-1,65,65,65,65,-1,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,67,65,65,65,65,65,65},
    /*  25 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,-1,61,61,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,64,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  26 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,62,-1,-1,-1,-1,-1,-1,-1,-1,59,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  27 */ {57,57,-1,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57},
    /*  28 */ {-1,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  29 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,66,-1,-1,-1,-1,-1,-1,-1,66,66,66,-1,64,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  30 */ {65,65,-1,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65},
    /*  31 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  32 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,71,-1,71,-1,-1,62,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  33 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,66,-1,-1,-1,-1,-1,-1,-1,66,66,66,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    /*  34 */ {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

static const char lexAccept[] = {
    /*   0 */  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    /*  10 */  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    /*  20 */  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    /*  30 */  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    /*  40 */  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
    /*  50 */  4,  4,  4,  4,  4,  4,  4,  0,  4,  4,
    /*  60 */  0,  4,  4,  0,  4,  0,  4,  0,  0,  0,
    /*  70 */  0,  0
};

#line 12 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"

// nextState(state,c) is given the current state number and input
// character and evaluates to the next state.
#define nextState(state,c) (lexNext[lexStateMap[state]][lexCharMap[c]])

int Java5Lex::getNextLexeme() {
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
#line 124 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        ;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 2:
#line 87 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return NOT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 3:
#line 108 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return MOD;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 4:
#line 105 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return AND;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 5:
#line 75 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return LPAR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 6:
#line 76 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return RPAR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 7:
#line 103 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return STAR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 8:
#line 101 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return PLUS;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 9:
#line 82 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return COMMA;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 10:
#line 102 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return MINUS;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 11:
#line 83 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return DOT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 12:
#line 104 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return DIV;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 13:
      case 58:
      case 61:
      case 64:
      case 66:
#line 39 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return INTEGERLITERAL;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 14:
#line 90 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return COLON;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 15:
#line 81 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return SEMICOLON;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 16:
#line 85 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return LT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 17:
#line 84 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return ASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 18:
#line 86 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return GT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 19:
#line 89 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return QUESTION;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 20:
#line 92 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return AT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 21:
#line 48 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return nameOrKeyWord(getText());
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 22:
#line 79 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return LB;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 23:
#line 80 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return RB;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 24:
#line 107 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return XOR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 25:
#line 77 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return LC;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 26:
#line 106 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return OR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 27:
#line 78 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return RC;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 28:
#line 88 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return COMPLEMENT;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 29:
#line 96 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return NEQ;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 30:
#line 43 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return STRINGLITERAL;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 31:
#line 119 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return MODASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 32:
#line 97 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return ANDAND;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 33:
#line 116 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return ANDASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 34:
#line 114 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return STARASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 35:
#line 99 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return PLUSPLUS;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 36:
#line 112 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return PLUSASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 37:
#line 100 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return MINUSMINUS;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 38:
#line 113 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return MINUSASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 39:
      case 59:
      case 62:
#line 41 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return FLOATLITERAL;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 40:
#line 50 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        { int i;
        							  SourcePosition startpos = getPos();
        							  while(i = input()) {
        							    if(i < 0) {
        							      flushBuf();  /* Discard lexeme. */
        							    } else if(i == '*' && look(1) == '/') {
        							     input();
        							     break;       /* Recognized comment.*/
        							    }
        							  }
        							  if(i == 0) {
        							    error( startpos,_T("End of file in comment\n") );
                                      }
        							}
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 41:
#line 65 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        { int i;
        							  while(i = input()) {
        							    if(i < 0) {
        							      flushBuf();  /* Discard lexeme. */
        							    } else if(i == '\n') {
        							      break;
        							    }
                                      }
        							}
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 42:
#line 115 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return DIVASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 43:
#line 109 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return SHL;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 44:
#line 94 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return LE;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 45:
#line 93 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return EQ;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 46:
#line 95 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return GE;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 47:
#line 110 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return SSHR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 48:
#line 118 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return XORASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 49:
#line 117 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return ORASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 50:
#line 98 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return OROR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 51:
#line 45 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return CHARACTERLITERAL;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 52:
#line 91 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return ELLIPSIS;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 53:
#line 120 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return SHLASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 54:
#line 121 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return SSHRASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 55:
#line 111 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return USHR;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
        break;
      case 56:
#line 122 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"
        return USHRASSIGN;
#line 94 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
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

#line 127 "C:\\mytools2015\\ParserGen\\java\\Java5.lex"

typedef struct {
  TCHAR *m_name;
  int    m_token;
} ReservedWords;

static ReservedWords wordTable[] = {
  _T("abstract"    ) ,ABSTRACT
 ,_T("assert"      ) ,ASSERT
 ,_T("boolean"     ) ,TYPEBOOLEAN
 ,_T("break"       ) ,BREAK
 ,_T("byte"        ) ,TYPEBYTE
 ,_T("case"        ) ,CASE
 ,_T("catch"       ) ,CATCH
 ,_T("char"        ) ,TYPECHAR
 ,_T("class"       ) ,CLASS
 ,_T("continue"    ) ,CONTINUE
 ,_T("default"     ) ,DEFAULT
 ,_T("do"          ) ,DO
 ,_T("double"      ) ,TYPEDOUBLE
 ,_T("else"        ) ,ELSE
 ,_T("enum"        ) ,ENUM
 ,_T("extends"     ) ,EXTENDS
 ,_T("false"       ) ,BOOLEANLITERAL
 ,_T("final"       ) ,FINAL
 ,_T("finally"     ) ,FINALLY
 ,_T("float"       ) ,TYPEFLOAT
 ,_T("for"         ) ,FOR
 ,_T("if"          ) ,IF
 ,_T("implements"  ) ,IMPLEMENTS
 ,_T("import"      ) ,IMPORT
 ,_T("instanceof"  ) ,INSTANCEOF
 ,_T("int"         ) ,TYPEINT
 ,_T("interface"   ) ,INTERFACE
 ,_T("long"        ) ,TYPELONG
 ,_T("native"      ) ,NATIVE
 ,_T("new"         ) ,NEW
 ,_T("null"        ) ,NULLLITERAL
 ,_T("package"     ) ,PACKAGE
 ,_T("private"     ) ,PRIVATE
 ,_T("protected"   ) ,PROTECTED
 ,_T("public"      ) ,PUBLIC
 ,_T("return"      ) ,RETURN
 ,_T("short"       ) ,TYPESHORT
 ,_T("static"      ) ,STATIC
 ,_T("strictfp"    ) ,STRICTFP
 ,_T("super"       ) ,SUPER
 ,_T("switch"      ) ,SWITCH
 ,_T("synchronized") ,SYNCHRONIZED
 ,_T("this"        ) ,THISLITERAL
 ,_T("throw"       ) ,THROW
 ,_T("throws"      ) ,THROWS
 ,_T("transient"   ) ,TRANSIENT
 ,_T("true"        ) ,BOOLEANLITERAL
 ,_T("try"         ) ,TRYTOKEN
 ,_T("void"        ) ,TYPEVOID
 ,_T("volatile"    ) ,VOLATILE
 ,_T("while"       ) ,WHILE
};

typedef StrHashMap<int> HashMapType;

class ReservedWordMap : public HashMapType {
public:
  ReservedWordMap(int capacity) : HashMapType(capacity) {
    for(int i = 0; i < ARRAYSIZE(wordTable); i++) {
      put(wordTable[i].m_name,wordTable[i].m_token);
	}
  }
};

static ReservedWordMap reservedWordMap(249);

static int nameOrKeyWord(const TCHAR *lexeme) {
  int *p = reservedWordMap.get(lexeme);
  return p ? *p : IDENTIFIER;
}

void Java5Lex::findBestHashMapSize() {
  IntTreeMap<CompactIntArray> cl;
  int bestCapacity;
  for(int capacity = 3; capacity < 2000; capacity++) {
    ReservedWordMap ht(capacity);
	cl.put((int)ht.getCapacity(), ht.getLength());
	if(ht.getMaxChainLength() == 1) {
	  bestCapacity = capacity;
	  break;
	}
  }

  for(Iterator<Entry<int, CompactIntArray> > it = cl.entrySet().getIterator(); it.hasNext();) {
    Entry<int, CompactIntArray> &e = it.next();
    int capacity = e.getKey();
	const CompactIntArray &chainLength = e.getValue();
	printf("Capacity %4d:",capacity);
	for(size_t l = 0; l < chainLength.size(); l++) {
	  printf(" (%d,%3d)",(int)l,chainLength[l]);
	}
	printf("\n");
  }
  printf("Capacity:%d gives best hashmap\n",bestCapacity);
}
#line 115 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
