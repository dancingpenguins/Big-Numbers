/* DO NOT EDIT THIS FILE - it is machine generated */
#pragma once
#include <Scanner.h>

#line 2 "C:\\mytools2015\\FindStrings\\FindStrings.lex"
#pragma once

 /* This part goes to the h file */

typedef enum {
  _EOI
 ,OLDSTRING
 ,OLDCHAR
 ,NEWSTRING
 ,NEWCHAR
 ,DIRECTIVE
} InputToken;

class FindStringsLex : public Scanner {
public:
  FindStringsLex(LexStream *inputStream = NULL) : Scanner(inputStream) {
  }
  int  getNextLexeme();
};


#line 5 "C:\\mytools2015\\parsergen\\lib\\lexgencpp.par"
