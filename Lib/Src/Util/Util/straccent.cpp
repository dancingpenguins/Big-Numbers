#include "pch.h"

#ifndef UNICODE

const unsigned char String::upperCaseAccentTranslate[256] = {
   0,     1,     2,     3,    4,     5,     6,     7,    8,     9,    10,    11,   12,    13,    14,    15, 
  16,    17,    18,    19,   20,    21,    22,    23,   24,    25,    26,    27,   28,    29,    30,    31, 
  32,    33,    34,    35,   36,    37,    38,    39,   40,    41,    42,    43,   44,    45,    46,    47, 
  48,    49,    50,    51,   52,    53,    54,    55,   56,    57,    58,    59,   60,    61,    62,    63, 
  64,    65,    66,    67,   68,    69,    70,    71,   72,    73,    74,    75,   76,    77,    78,    79, 
  80,    81,    82,    83,   84,    85,    86,    87,   88,    89,    90,   198,  216,   197,    94,    95, 
  96,    65,    66,    67,   68,    69,    70,    71,   72,    73,    74,    75,   76,    77,    78,    79, 
  80,    81,    82,    83,   84,    85,    86,    87,   88,    89,    90,   123,  124,   125,   126,   127, 
 128,   129,   130,   131,  132,   133,   134,   135,  136,   137,   138,   139,  140,   141,   142,   143, 
 144,   145,   146,   147,  148,   149,   150,   151,  152,   153,   154,   155,  156,   157,   158,   159, 
 160,   161,   162,   163,  164,   165,   166,   167,  168,   169,   170,   171,  172,   173,   174,   175, 
 176,   177,   178,   179,  180,   181,   182,   183,  184,   185,   186,   187,  188,   189,   190,   191, 
 'A',   'A',   'A',   'A',  '[',   ']',   '[',   'C',  'E',   'E',   'E',   'E',  'I',   'I',   'I',   'I', 
 'D',   'N',   'O',   'O',  'O',   'O',   '\\',  215,  '\\',  'U',   'U',   'U',  'Y',   'Y',   254,   223, 
 'A',   'A',   'A',   'A',  '[',   ']',   '[',   'C',  'E',   'E',   'E',   'E',  'I',   'I',   'I',   'I', 
 208,   'N',   'O',   'O',  'O',   'O',   '\\',  247,  '\\',  'U',   'U',   'U',  'Y',   'Y',   254,   'Y'
};

int streaicmp(const char *s1, const char *s2) {
  return strtabcmp(s1, s2, String::upperCaseAccentTranslate);
}

int strneaicmp(const char *s1, const char *s2, int n) {
  return strntabcmp(s1, s2, n, String::upperCaseAccentTranslate);
}

#endif
