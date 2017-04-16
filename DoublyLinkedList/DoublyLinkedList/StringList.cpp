#pragma once
/*
Program: StingList.cpp
Author: Demetri Van Sickle
Date: 4/15/17
IDE: Visual Studio 2015
Program:
	Contains the implementation for the StringList class
*/

#include <iostream>
#include "StringList.h"

using namespace std;

StringList::StringList()
{
	head = NULL;
	tail = NULL;
	itemsInList = 0;
}

StringList::~StringList()
{
}

bool StringList::insert(string nameToInsert)
{
	if (nameToInsert.empty() == true)
	{
		return false;
	}

	Node* newNode = new Node;
	newNode->data = nameToInsert;
	newNode->nextAddress = NULL;
	newNode->prevAddress = NULL;

	//If list is empty
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		itemsInList++;
		return true;
	}

	if()
}
