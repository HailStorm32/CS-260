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
	removeAll();
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
	
	//Cycle until we find a spot to put the data
	while (currentNode != NULL && insertAfter(dataToInsert, currentNode->data) == true)
	{
		prevNode = currentNode;
		currentNode = currentNode->nextAddress;
	}

	//If at the end of the list
	if (currentNode == NULL)
	{
		prevNode->nextAddress = newNode;
		newNode->prevAddress = prevNode;

		tail = newNode;

		itemsInList++;
		return true;
	}
	//If at the begining of the list
	else if (currentNode->prevAddress == NULL)
	{
		newNode->nextAddress = head;
		head->prevAddress = newNode;

		head = newNode;

		itemsInList++;
		return true;
	}
	//If else where in the list
	else
	{
		newNode->nextAddress = currentNode;
		newNode->prevAddress = currentNode->prevAddress;
		prevNode->nextAddress = newNode;
		currentNode->prevAddress = newNode;
		return true;
	}

}

int StringList::remove(string dataToRemove)
{
	if (dataToRemove.empty() == true || head == NULL || find(dataToRemove) == 0)
	{
		return 0;
	}

	Node* currentNode = NULL;
	Node* nextNode = NULL;
	Node* prevNode = NULL;

	unsigned int itemsDeleted = 0;

	currentNode = head;

	//Go through the list
	while (currentNode != NULL)
	{
		//If the two peices of data match
		if (currentNode->data == dataToRemove)
		{
			//If deleting the first item in the list
			if (currentNode->prevAddress == NULL && currentNode->data == dataToRemove)
			{
				//and its not the only item
				if (itemsInList != 1)
				{
					nextNode = currentNode->nextAddress;
					head = currentNode->nextAddress;

					delete currentNode;

					//Reset the prevAddres pointer from the node after the one we deleted
					nextNode->prevAddress = NULL;

					itemsInList--;
					itemsDeleted++;

					//Set our currentNode to the "new" head
					currentNode = head;
					prevNode = currentNode->prevAddress;
				}
				else if (itemsInList == 0)
				{
					delete currentNode;

					head = NULL;
					tail = NULL;

					itemsDeleted++;
					itemsInList--;
					return itemsDeleted;
				}
			}
			//If deleting the last item in the list
			else if (currentNode->nextAddress == NULL)
			{
				prevNode->nextAddress = NULL;
				tail = prevNode;

				delete currentNode;

				itemsDeleted++;
				itemsInList--;

				currentNode = NULL;

			}
			else
			{
				nextNode = currentNode->nextAddress;
				prevNode->nextAddress = nextNode;
				nextNode->prevAddress = prevNode;

				delete currentNode;

				itemsDeleted++;
				itemsInList--;

				currentNode = nextNode;
			}
		}
		else
		{
			prevNode = currentNode;
			currentNode = currentNode->nextAddress;
		}
	}

	return itemsDeleted;
}

void StringList::removeAll()
{
	if (head == NULL)
	{
		return;
	}

	recursiveRemoveAll(tail);

	head = NULL;
	tail = NULL;

	itemsInList = 0;
}

int StringList::totalItems()
{
	return itemsInList;
}

void StringList::print(bool printBackward)
{
	if (head == NULL || tail == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	cout << "List contains: ";

	if (printBackward == false)
	{
		recursivePrintForward(head);
	}
	else
	{
		recursivePrintBackward(tail);
	}
	cout << endl;

}

int StringList::find(string dataToFind)
{
	if (head == NULL || dataToFind.empty() == true)
	{
		return 0;
	}

	return recursiveFind(head, dataToFind);
}

int StringList::findLetter(char letterToFind)
{
	if (head == NULL || letterToFind == NULL)
	{
		return 0;
	}

	return recursiveFindLetter(head, letterToFind);
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

int StringList::recursiveRemoveAll(Node* currentNode)
{
	if (currentNode == NULL)
	{
		return 1;
	}

	Node* prevNode = currentNode->prevAddress;

	delete currentNode;

	recursiveRemoveAll(prevNode);
	return 0;
}

bool StringList::recursivePrintForward(Node * currentNode)
{
	if (currentNode == NULL)
	{
		return true;
	}

	cout << currentNode->data << ", ";

	recursivePrintForward(currentNode->nextAddress);

	return false;
}

bool StringList::recursivePrintBackward(Node * currentNode)
{
	if (currentNode == NULL)
	{
		return true;
	}

	cout << currentNode->data << ", ";

	recursivePrintBackward(currentNode->prevAddress);

	return false;
}

int StringList::recursiveFind(Node * currentNode, string dataToFind)
{
	int numberOfFinds = 0;

	if (currentNode == NULL)
	{
		return 0;
	}

	if (currentNode->data == dataToFind)
	{
		numberOfFinds++;
	}

	numberOfFinds += recursiveFind(currentNode->nextAddress, dataToFind);

	return numberOfFinds;
}

int StringList::recursiveFindLetter(Node * currentNode, const char& letterToFind)
{
	int numberOfFinds = 0;

	if (currentNode == NULL)
	{
		return 0;
	}

	numberOfFinds += recursiveScanString(currentNode->data, 0, letterToFind);

	numberOfFinds += recursiveFindLetter(currentNode->nextAddress, letterToFind);

	return numberOfFinds;
}

int StringList::recursiveScanString(const string& dataToScan, int stringIndx, const char& letterToFind)
{
	int numOfFinds = 0;

	if (stringIndx == dataToScan.length())
	{
		return 0;
	}

	if (toupper(dataToScan[stringIndx]) == toupper(letterToFind))
	{
		numOfFinds++;
	}

	numOfFinds += recursiveScanString(dataToScan, ++stringIndx, letterToFind);

	return numOfFinds;
}
