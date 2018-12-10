// TODO -- needs implementation
#include "word.h"

Word::Word()
{
    count = 0;
}

Word::Word(string newWord)
{
  word = newWord;
  count = 1;
}

string Word::getWord()
{
	return word;
}

unsigned int Word ::getCount()
{
	return count;
}

void Word ::setWord(string newWord)
{
	word = newWord;
}

void Word ::incrementCount(unsigned int amount)
{
	count += amount;
}

bool Word ::operator> (const Word& otherWord)
{
	return uppercase(this -> word) > uppercase(otherWord.word);
}

bool Word ::operator< (const Word& otherWord)
{
	return uppercase(this -> word) < uppercase(otherWord.word);
}

bool Word ::operator==(const Word& otherWord)
{
	return uppercase(this -> word) == uppercase(otherWord.word);
}

ostream& operator<<(ostream& outs, const Word& w)
{

	outs << w.word << ':' << w.count;
	return outs;
}
/*
istream& operator>>(istream& ins, Word& w)
{

	getline(ins, w.word);
	return ins;
}
*/
string Word::uppercase(string s)
{
  transform(s.begin(), s.end(),  s.begin(), ::toupper);
  return s;
}
