#pragma once
/*
Program: StingListTest.cpp
Author: Demetri Van Sickle
Date: 4/15/17
IDE: Visual Studio 2015
Program:
	Contains the definition for the StringList class
*/

class StringList
{
public:
	StringList();

	~StringList();
	
	bool insert(string nameToInsert);

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
};