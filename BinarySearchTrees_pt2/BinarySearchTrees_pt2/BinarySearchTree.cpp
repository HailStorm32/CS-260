/*
Author: Demetri Van Sickle
Date: 5/12/17
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
	Node* prevNode;
	Node* newNode = new Node;

	bool  insertLeft = false;

	newNode->data = dataToInsert;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	//If only item in tree
	if (head == NULL)
	{
		head = newNode;
		return true;
	}

	currentNode = head;

	//Cycle through tree until we find a null node that we can place data into
	while (currentNode != NULL)
	{
		if (insertRight(newNode->data, currentNode->data))
		{
			prevNode = currentNode;
			currentNode = currentNode->rightChild;
			insertLeft = false;
		}
		else
		{
			prevNode = currentNode;
			currentNode = currentNode->leftChild;
			insertLeft = true;
		}
	}

	//Attach the data on th right branch
	if (insertLeft == false)
	{
		prevNode->rightChild = newNode;
	}
	else
	{
		prevNode->leftChild = newNode;
	}

	return true;
}

void BinarySearchTree::printInOrder()
{
	printInOrderR(head);
	cout << endl;
}

void BinarySearchTree::printPostOrder()
{
	printPostOrderR(head);
	cout << endl;
}

void BinarySearchTree::printPreOrder()
{
	printPreOrderR(head);
	cout << endl;
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

void BinarySearchTree::printInOrderR(Node * currentNode)
{
	if (currentNode != NULL)
	{
		printInOrderR(currentNode->leftChild);
		cout << currentNode->data << " ";
		printInOrderR(currentNode->rightChild);
	}
}

void BinarySearchTree::printPostOrderR(Node* currentNode)
{
	if (currentNode != NULL)
	{
		printInOrderR(currentNode->leftChild);
		printInOrderR(currentNode->rightChild);
		cout << currentNode->data << " ";
	}
}

void BinarySearchTree::printPreOrderR(Node* currentNode)
{
	if (currentNode != NULL)
	{
		cout << currentNode->data << " ";
		printInOrderR(currentNode->leftChild);
		printInOrderR(currentNode->rightChild);
	}
}