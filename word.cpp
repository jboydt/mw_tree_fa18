#include "word.h"

Word::Word(string newWord) {
  word = newWord;
  count = 1;
}

string Word::getWord() {
  return word;
}

unsigned int Word::getCount() {
  return count;
}

void Word::setWord(string newWord) {
  string = newWord;
}

void Word::incrementCount(unsigned int amount) {
  count += amount;
}

// operator>
bool Word::operator>(const Word& otherWord) {
  // TODO
}

// operator<
bool Word::operator<(const Word& otherWord) {
  // TODO
}

// operator==
bool Word::operator==(const Word& otherWord) {
  // TODO
}

friend ostream& operator<<(ostream& outs, const Word& w) {
  // TODO
}

string Word::uppercase(string s) {
  // TODO
}
