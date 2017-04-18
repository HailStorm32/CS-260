#pragma once
/*
Program: StingListTest.cpp
Author: Demetri Van Sickle
Date: 4/15/17
IDE: Visual Studio 2015
Program:
	Contains the definition for the StringList class
*/
#include <string>

using namespace std;

class StringList
{
public:
	StringList();

	~StringList();
	
	/*
	Input:
		string - no empty strings
	Output:
		True - string inserted into list
		False - string NOT inserted into the list
	*/
	bool insert(string dataToInsert);

	/*
	Input:
		string - no empty string
	Output:
		int - number of times given data was removed
	*/
	int remove(string dataToRemove);

private:
	struct Node
	{
		string data;
		Node* prevAddress;
		Node* nextAddress;
	};
	
	unsigned int itemsInList;
	Node* head;
	Node* tail;

	/*
	Input:
		string - no empty strings
	Output:
		True - put dataToInsert AFTER the dataInSlot
		False - put dataToInsert BEFORE the dataInSlot
	*/
	bool insertAfter(const string& dataToInsert, const string& dataInSlot) const;
};