#pragma once

#include <algorithm>
#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Word {
public:
  Word();
  Word(string newWord);


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

  // operator>>
//  friend istream& operator>>(istream& ins, Word& w);

private:
  string word;
  unsigned int count;

  string uppercase(string s);
};
