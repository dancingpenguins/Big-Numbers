/* DO NOT EDIT THIS FILE - it is machine generated */
#line 28 "C:\\mytools2015\\ParserGen\\Olm627\\Olm627.y"
#include "stdafx.h"
#include "Olm627Parser.h"

#line 33 "C:\\mytools2015\\parsergen\\lib\\parsergencpp.par"

#pragma warning(disable : 4312)

typedef char TableType;

/****************************************************************************\
* Bitset containing 1-bits for compressed states and 0-bits for              *
* uncompressed states. Used by ParserTable to determine how to               *
* interpret the entry in the action-table                                    *
* Number of bytes in bitset = (statecount-1)/8+1                             *
\****************************************************************************/
static const BYTE compressedSet[2] = { 0x5e,0x0f
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
#define act0002 (void*)0x00050005    /* shift to 5 on f                          */
#define act0003 (void*)0x00070005    /* shift to 7 on f                          */
#define act0004 (void*)0x00080004    /* shift to 8 on d                          */
#define act0006 (void*)0x000a0003    /* shift to 10 on c                         */
#define act0008 (void*)0xffff0000    /* reduce by 1 on EOI                       */
#define act0009 (void*)0xfffe0000    /* reduce by 2 on EOI                       */
#define act0010 (void*)0xfffd0000    /* reduce by 3 on EOI                       */
#define act0011 (void*)0xfffc0000    /* reduce by 4 on EOI                       */

static const TableType act0000[] = {   2,   1,   2,   2,   3};
static const TableType act0005[] = {   2,   3,   9,   4,  -5};
static const TableType act0007[] = {   2,   3,  -5,   4,  11};

// Total size of uncompressed actNNNN tables:24 bytes.

static const void *action[12] = {
   act0000,act0001,act0002,act0003,act0004,act0005,act0006,act0007,act0008,act0009
  ,act0010,act0011
}; // Size of table:96 bytes.

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
static const TableType succ0000[] = {  1,   7,   1};
static const TableType succ0002[] = {  1,   8,   4};
static const TableType succ0003[] = {  1,   8,   6};

// Total size of all succNNNN tables:12 bytes.

static const TableType *successor[12] = {
   succ0000,NULL    ,succ0002,succ0003,NULL    ,NULL    ,NULL    ,NULL    ,NULL    ,NULL
  ,NULL    ,NULL
}; // Size of pointertable:96 bytes.

/****************************************************************************\
* The productionLength[] array is indexed by production number and holds     *
* the number of symbols on the right side of each production.                *
\****************************************************************************/
static const unsigned char productionLength[6] = {
  /*   0 */    1,   3,   3,   3,   3,   1
}; // Size of table:8 bytes.

/****************************************************************************\
* The leftSide[] array is indexed by production number, and holds the        *
* nonTerminal symbol on the left side of each production.                    *
\****************************************************************************/
static const TableType leftSide[6] = {
  /*   0 */    6,   7,   7,   7,   7,   8
}; // Size of table:8 bytes.

/****************************************************************************\
* The rightSide[] matrix is indexed by production number and holds           *
* the right side symbols of each production.                                 *
* Compressed and only used for debugging.                                    *
\****************************************************************************/
static const TableType rightSideTable[14] = {
  /*   0 */    7
  /*   1 */ ,  1,  8,  4
  /*   2 */ ,  1,  5,  3
  /*   3 */ ,  2,  8,  3
  /*   4 */ ,  2,  5,  4
  /*   5 */ ,  5
}; // Size of table:16 bytes.

/****************************************************************************\
* The symbolName[] array is indexed by symbol and holds                      *
* the name of each symbol (terminal or nonTerminal).                         *
* Used for debugging.                                                        *
\****************************************************************************/
static const TCHAR *symbolName[9] = {
  /*   0 */ _T("EOI"),
  /*   1 */ _T("a"),
  /*   2 */ _T("b"),
  /*   3 */ _T("c"),
  /*   4 */ _T("d"),
  /*   5 */ _T("f"),
  /*   6 */ _T("start"),
  /*   7 */ _T("S"),
  /*   8 */ _T("A")
}; // Total size of strings:40 bytes, size of pointertable:72 bytes.

static const ParserCharTables Olm627Tables_s(compressedSet, compressedLasets
                                            ,action, successor, productionLength, leftSide
                                            ,rightSideTable, symbolName
                                            ,6, 9, 6, 12);

const ParserTables *Olm627Tables = &Olm627Tables_s;
// Size of Olm627Tables_s: 88 bytes. Size of Olm627Tables:8 bytes


// Total size of table data:472 bytes.

