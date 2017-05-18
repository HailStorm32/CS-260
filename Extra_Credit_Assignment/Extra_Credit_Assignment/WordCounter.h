/*
Author: Demetri Van Sickle
Date: 5/18/17
*/
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <list>

using namespace std;

const int ILLEGAL_CHARS_SIZE = 5;

class WordCounter
{
public:
	WordCounter(string fileToRead);

	~WordCounter();

	bool begin();

private:
	map<string, int> uniqueWords;

	ifstream fileRead;

	list<string> listOfWords;

	/////////////////////////////////////////////////////////

	list<string>* findWords(string lineOfText);

	const char illegalChars[ILLEGAL_CHARS_SIZE] = {'.', '?', '!', ',' };

	string removeIllegalChars(string lineOfText);

	string fileToRead;

};
