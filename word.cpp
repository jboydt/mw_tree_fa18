// TODO -- needs implementation
	#include "word.h"

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
		return this -> word > otherWord.word;
	}
	
	bool Word ::operator< (const Word& otherWord) 
	{
		return this -> word < otherWord.word;
	}
	
	bool Word ::operator==(const Word& otherWord) 
	{
		return this -> word == otherWord.word;
	}
	
	friend ostream& operator<<(ostream& outs, const Word& w) 
	{
		
		outs << w.word;
		return outs;
	}
	
	friend ostream& operator>>(ostream& outs, const Word& w) 
	{
		
		outs >> w.word;
		return outs;
	}
	
	string uppercase(string s) 
	{
	
	}
