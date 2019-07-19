#pragma once

class DFARegex;

class RegexIStream {
private:
  DFARegex *m_regex;
  RegexIStream(const RegexIStream &);            // not defined
  RegexIStream &operator=(const RegexIStream &); // not defined
  void cleanup();
public:
  RegexIStream() : m_regex(NULL) {
  }
  RegexIStream(const StringArray &pattern, bool ignoreCase = false) : m_regex(NULL) {
    compilePattern(pattern, ignoreCase);
  }
  void compilePattern(const StringArray &pattern, bool ignoreCase = false);
  virtual ~RegexIStream() {
    cleanup();
  }
  int match(std::istream &in, String *matchedString = NULL) const;
};