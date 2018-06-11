/* DO NOT EDIT THIS FILE - it is machine generated */
#pragma once
#include <Scanner.h>

#line 2 "C:\\mytools2015\\Lib\\Src\\Expression\\Expression.lex"
#pragma once

 /* This part goes to the h file */

#include <LRParser.h>

namespace Expr {

class ExpressionLex : public Scanner {
private:
  LRparser *m_parser; // if set, redirect errors to parsers verror-routine
public:
  ExpressionLex(LexStream *inputStream = NULL) : Scanner(inputStream) {
    m_parser = NULL;
  }
  void setParser(LRparser *parser) {
    m_parser = parser;
  }

  int    getNextLexeme();
  void   verror(const SourcePosition &pos, _In_z_ _Printf_format_string_ TCHAR const * const format, va_list argptr);
  static ExpressionInputSymbol nameOrKeyWord(const _TUCHAR *lexeme);
};

}; // namespace Expr

#line 5 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"

