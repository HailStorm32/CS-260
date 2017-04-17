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

bool StringList::insert(string dataToInsert)
{
	if (dataToInsert.empty() == true)
	{
		return false;
	}

	Node* newNode = new Node;
	newNode->data = dataToInsert;
	newNode->nextAddress = NULL;
	newNode->prevAddress = NULL;

	Node* currentNode = NULL;
	Node* prevNode = NULL;

	//If list is empty
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		itemsInList++;
		return true;
	}

	currentNode = head;

	while (currentNode != NULL && insertAfter(dataToInsert, currentNode->data) == true)
	{
		prevNode = currentNode;
		currentNode = currentNode->nextAddress;
	}

	//Reached the end of the list
	if (currentNode == NULL)
	{
		prevNode->nextAddress = newNode;
		newNode->prevAddress = prevNode;
		
		tail = newNode;

		itemsInList++;
		return true;
	}
	else if (currentNode->prevAddress == NULL)
	{
		newNode->nextAddress = head;
		head->prevAddress = newNode;
		
		head = newNode;

		itemsInList++;
		return true;
	}
	else
	{
		newNode->nextAddress = currentNode;
		newNode->prevAddress = currentNode->prevAddress;
		prevNode->nextAddress = newNode;
		return true;
	}

}

bool StringList::insertAfter(const string& dataToInsert, const string& dataInSlot) const
{
	unsigned int indx = 0;
	unsigned int minStringSize = dataToInsert.length();

	if (dataToInsert.length() > dataInSlot.length())
	{
		minStringSize = dataInSlot.length();
	}

	//Keep moving through the two strings until two chars of the same indx != OR we have reached the end of our shortest string
	while (indx <= minStringSize && tolower(dataToInsert[indx]) == tolower(dataInSlot[indx]))
	{
		indx++;
	}

	//If the two strings are the same (ie: Bird == biRd)
	if (indx > minStringSize)
	{
		//It doesn't matter where we put the string, but return false to put it before
		return false;
	}

	if (tolower(dataToInsert[indx]) > tolower(dataInSlot[indx]))
	{
		return true;
	}
	else
	{
		return false;
	}
}
