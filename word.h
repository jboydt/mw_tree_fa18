#pragma once

#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Word {
public:
  Word(string newWord);

  // TODO
  // getters and setters
  string getWord();
  unsigned int getCount();

  void setWord(string newWord);
  void incrementCount(unsigned int amount = 1);

  // operator>
  bool operator>(const Word& otherWord);

  // operator<
  bool operator<(const Word& otherWord);

  // operator==
  bool operator==(const Word& otherWord);

  // operator<<
  friend ostream& operator<<(ostream& outs, const Word& w);

private:
  string word;
  unsigned int count;

  string uppercase(string s);
};
