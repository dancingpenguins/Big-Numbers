/* DO NOT EDIT THIS FILE - it is machine generated */
#include "stdafx.h"
#include "olm641parser.h"


#pragma warning(disable : 4312)

typedef char TableType;

/****************************************************************************\
* Bitset containing 1-bits for compressed states and 0-bits for              *
* uncompressed states. Used by ParserTable to determine how to               *
* interpret the entry in the action-table                                    *
* Number of bytes in bitset = (statecount-1)/8+1                             *
\****************************************************************************/
static const BYTE compressedSet[3] = { 0xda,0xf6,0x1f
}; // Size of table:4 bytes.

/****************************************************************************\
* The action matrix holds the parse action(state,terminal)                   *
* Used in LRParser::parserStep().                                            *
* 2 different formats are used:Compressed and Uncompressed.                  *
*                                                                            *
* Compressed:When there is only 1 possible action in the state.              *
*            or all actions are reduce by the same production.               *
*   If bit 16 (0x8000) is 0, there is only one possible action which is      *
*   encoded as:                                                              *
*      #define   act0001  (void*)((action << 16) | (token&0x7fff)            *
*   State index------+               |                |                      *
*   Highorder 16 bits = action-------+                |                      *
*   Loworder  15 bits = legal token-------------------+                      *
*                                                                            *
*   If bit 16 is 1, the loworder 15 bits is an index.                        *
*      #define   act0002  (void*)((action<<16)  |  0x8000 | (index&0x7fff))  *
*   State index------+               |                |        |             *
*   Highorder 16 bits = action-------+                |        |             *
*   Indicates that this is a multi-item-action-state--+        |             *
*   Loworder  15 bits = index into compressedLasets------------+             *
*                                                                            *
* compressedLasets contains all unique legal lookahead-sets for all          *
* multi-item-action-states.                                                  *
* Number of bytes in each bitset = (terminalcount-1)/8+1                     *
*                                                                            *
* Uncompressed states:                                                       *
*      TableType act0004[] =      { 3, 1, 2, 2,-2, 6, 1 };                   *
*   State index------+              |  |  |                                  *
*   Number of pairs in list---------+  |  |                                  *
*   Legal input symbol-----------------+  |                                  *
*   Action--------------------------------+                                  *
*                                                                            *
* If any uncompressed state has the same actionarray as a previous           *
* generated uncompressed state, a #define is generated to save space.        *
*                                                                            *
*                                                                            *
*   action = getAction(current state, current inputSymbol);                  *
*                                                                            *
*   action <  0   - Reduce by production p, p == -action.                    *
*   action == 0   - Accept. Reduce by production 0.                          *
*   action >  0   - Go to state s (=action),                                 *
*                   and push [s,input,pos] to parser stack.                  *
*                   Then read next symbol from input.                        *
*   action == _ParserError - not found (=unexpected input).                  *
\****************************************************************************/
#define compressedLasets NULL

#define act0001 (void*)0x00000000    /* reduce by 0 on EOI                       */
#define act0003 (void*)0x00090005    /* shift to 9 on z                          */
#define act0004 (void*)0x000a0006    /* shift to 10 on x                         */
#define act0006 (void*)0x00050003    /* shift to 5 on d                          */
#define act0007 (void*)0xfffd0000    /* reduce by 3 on EOI                       */
#define act0009 (void*)0xfffc0000    /* reduce by 4 on EOI                       */
#define act0010 (void*)0xfffb0000    /* reduce by 5 on EOI                       */
#define act0012 (void*)0x00120006    /* shift to 18 on x                         */
#define act0013 (void*)0xfff80000    /* reduce by 8 on EOI                       */
#define act0014 (void*)0x00130006    /* shift to 19 on x                         */
#define act0015 (void*)0x00080004    /* shift to 8 on f                          */
#define act0016 (void*)0xffff0000    /* reduce by 1 on EOI                       */
#define act0017 (void*)0xfff40000    /* reduce by 12 on EOI                      */
#define act0018 (void*)0xfffe0000    /* reduce by 2 on EOI                       */
#define act0019 (void*)0xfff70000    /* reduce by 9 on EOI                       */
#define act0020 (void*)0xfff60000    /* reduce by 10 on EOI                      */

static const TableType act0000[] = {   2,   1,   2,   3,   5};
static const TableType act0002[] = {   2,   2,   6,   4,   8};
static const TableType act0005[] = {   3,   0,  -6,   5,  -6,   6,  -7};
static const TableType act0008[] = {   2,   1,  15,   3,   5};
static const TableType act0011[] = {   2,   0, -11,   5,  17};

// Total size of uncompressed actNNNN tables:40 bytes.

static const void *action[21] = {
   act0000,act0001,act0002,act0003,act0004,act0005,act0006,act0007,act0008,act0009
  ,act0010,act0011,act0012,act0013,act0014,act0015,act0016,act0017,act0018,act0019
  ,act0020
}; // Size of table:168 bytes.

/****************************************************************************\
* The successor matrix is used when the parser has reduced by prod A -> alfa *
* Used by LRParser to find newstate = successor(state,A).                    *
*                                                                            *
*                  succ0007[] = { 3, 5,3 , 6,2, 8,5 };                       *
*   Current state-------+         |  | |                                     *
*   Number of pairs in list ------+  | |                                     *
*   NonTerminal A--------------------+ |                                     *
*   Go to this state-------------------+                                     *
\****************************************************************************/
static const TableType succ0000[] = {  3,   8,   1,   9,   3,  11,   4};
static const TableType succ0002[] = {  1,  12,   7};
static const TableType succ0006[] = {  2,   9,  11,  11,  12};
static const TableType succ0008[] = {  2,   9,  13,  11,  14};
static const TableType succ0011[] = {  1,  10,  16};
static const TableType succ0015[] = {  1,  12,  20};

// Total size of all succNNNN tables:36 bytes.

static const TableType *successor[21] = {
   succ0000,NULL    ,succ0002,NULL    ,NULL    ,NULL    ,succ0006,NULL    ,succ0008,NULL
  ,NULL    ,succ0011,NULL    ,NULL    ,NULL    ,succ0015,NULL    ,NULL    ,NULL    ,NULL
  ,NULL
}; // Size of pointertable:168 bytes.

/****************************************************************************\
* The productionLength[] array is indexed by production number and holds     *
* the number of symbols on the right side of each production.                *
\****************************************************************************/
static const unsigned char productionLength[13] = {
  /*   0 */    1,   4,   4,   2,   2,   2,   1,   1,   2,   3,
  /*  10 */    3,   0,   1
}; // Size of table:16 bytes.

/****************************************************************************\
* The leftSide[] array is indexed by production number, and holds the        *
* nonTerminal symbol on the left side of each production.                    *
\****************************************************************************/
static const TableType leftSide[13] = {
  /*   0 */    7,   8,   8,   8,   8,   8,   9,  11,  12,  12,
  /*  10 */   12,  10,  10
}; // Size of table:16 bytes.

/****************************************************************************\
* The rightSide[] matrix is indexed by production number and holds           *
* the right side symbols of each production.                                 *
* Compressed and only used for debugging.                                    *
\****************************************************************************/
static const TableType rightSideTable[26] = {
  /*   0 */    8
  /*   1 */ ,  1,  2,  9, 10
  /*   2 */ ,  1,  2, 11,  6
  /*   3 */ ,  1, 12
  /*   4 */ ,  9,  5
  /*   5 */ , 11,  6
  /*   6 */ ,  3
  /*   7 */ ,  3
  /*   8 */ ,  4,  9
  /*   9 */ ,  4, 11,  6
  /*  10 */ ,  4,  1, 12
  /*  12 */ ,  5
}; // Size of table:28 bytes.

/****************************************************************************\
* The symbolName[] array is indexed by symbol and holds                      *
* the name of each symbol (terminal or nonTerminal).                         *
* Used for debugging.                                                        *
\****************************************************************************/
static const TCHAR *symbolName[13] = {
  /*   0 */ _T("EOI"),
  /*   1 */ _T("a"),
  /*   2 */ _T("b"),
  /*   3 */ _T("d"),
  /*   4 */ _T("f"),
  /*   5 */ _T("z"),
  /*   6 */ _T("x"),
  /*   7 */ _T("start"),
  /*   8 */ _T("S"),
  /*   9 */ _T("A"),
  /*  10 */ _T("E"),
  /*  11 */ _T("B"),
  /*  12 */ _T("D")
}; // Total size of strings:56 bytes, size of pointertable:104 bytes.

static const ParserCharTables Olm641Tables_s(compressedSet, compressedLasets
                                            ,action, successor, productionLength, leftSide
                                            ,rightSideTable, symbolName
                                            ,7, 13, 13, 21);

const ParserTables *Olm641Tables = &Olm641Tables_s;
// Size of Olm641Tables_s: 88 bytes. Size of Olm641Tables:8 bytes


// Total size of table data:732 bytes.

