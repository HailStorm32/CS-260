/*
Author: Demetri Van Sickle
Date: 5/18/17
*/
#include "WordCounter.h"

WordCounter::WordCounter(string fileToRead)
{
	this->fileToRead = fileToRead;
}

WordCounter::~WordCounter()
{
}

bool WordCounter::begin()
{
	fileRead.open(fileToRead);

	while (!fileRead.eof())
	{

	}
}

list<string>* WordCounter::findWords(string lineOfText)
{
	string dataHolder;

	lineOfText.find('.', 1);
}

string WordCounter::removeIllegalChars(string lineOfText)
{
	return string();
}
