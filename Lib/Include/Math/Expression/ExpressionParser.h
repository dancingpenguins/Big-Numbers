/* DO NOT EDIT THIS FILE - it is machine generated */
#pragma once

#include <LRparser.h>

const extern ParserTables *ExpressionTables;

#line 3 "C:\\mytools2015\\Lib\\Src\\Math\\Expression\\Expression.y"
#include <Math/Expression/ExpressionSymbol.h>
#include <Math/Expression/ExpressionLex.h>
#include <Math/Expression/ParserTree.h>

class ExpressionParser : public LRparser {
public:
  ExpressionParser(ParserTree &tree, ExpressionLex *lex = NULL) : m_tree(tree), LRparser(*ExpressionTables,lex) {}
  void verror(const SourcePosition &pos, _In_z_ _Printf_format_string_ TCHAR const * const format, va_list argptr);
private:
  ParserTree &m_tree;
  ExpressionNode *m_dollardollar, **m_stacktop, *m_userstack[256];
  ExpressionNode *newNode(const SourcePosition &pos, ExpressionInputSymbol symbol, ... );
  int   reduceAction(        unsigned int prod);
  ExpressionNode *getStackTop(int fromtop)   { return m_stacktop[-fromtop];      }
  void  userStackInit()                            { m_stacktop = m_userstack;         }
  void  userStackShiftSymbol(unsigned int symbol)  { m_stacktop++;                     } // push 1 element (garbage) on userstack
  void  userStackPopSymbols( unsigned int count)   { m_stacktop -= count;              } // pop count symbols from userstack
  void  userStackShiftDollarDollar()               { *(++m_stacktop) = m_dollardollar; } // push($$) on userstack
  void  defaultReduce(       unsigned int prod)    { m_dollardollar  = *m_stacktop;    } // $$ = $1
};


#line 18 "C:\\mytools2015\\parsergen\\lib\\parsergencpp.par"

