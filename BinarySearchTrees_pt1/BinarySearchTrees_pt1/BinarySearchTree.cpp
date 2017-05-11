/*
Author: Demetri Van Sickle
Date: 5/8/17
IDE: Visual Studio 2015
Program: Main.cpp
Description:
		Contains the definition code for the BinarySearchTree class
*/

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	head = NULL;

	itemsInTree = 0;
}

BinarySearchTree::~BinarySearchTree()
{

}

bool BinarySearchTree::insert(string dataToInsert)
{
	//Make sure string isnt empty
	if (dataToInsert.empty())
	{
		return false;
	}

	Node* currentNode;
	//Node* prevNode;
	Node* newNode = new Node;

	newNode->data = dataToInsert;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	//If only item in tree
	if (head == NULL)
	{
		head = newNode;
		return true;
	}
	

	while (currentNode == NULL)
	{
		if (insertRight(newNode->data, currentNode->data))
		{
			currentNode = currentNode->rightChild;
		}
		else
		{
			currentNode = currentNode->leftChild;
		}
	}

	currentNode = newNode;

	return true;
}

bool BinarySearchTree::insertRight(const string & dataToInsert, const string & dataInSlot) const
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


