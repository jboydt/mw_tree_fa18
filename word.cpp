#include "word.h"

Word::Word(string newWord) {
  word = newWord;
  count = 1;
}

string Word::getWord() {
  // TODO
}

unsigned int Word::getCount() {
  // TODO
}

void Word::setWord(string newWord) {
  // TODO
}

void Word::incrementCount(unsigned int amount) {
  // TODO
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
