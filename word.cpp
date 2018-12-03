// TODO -- needs implementation
	#include "word.h"

	string Word::getWord() 
	{
		
	}
	unsigned int Word ::getCount() 
	{
		
		
	}
	
	void Word ::setWord(string newWord) 
	{
		
	}
	void Word ::incrementCount(unsigned int amount) 
	{
		
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
