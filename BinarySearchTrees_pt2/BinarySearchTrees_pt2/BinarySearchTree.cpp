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

void BinarySearchTree::printInOrder(const function<int(string, int)> &funcToCall)
{
	printInOrderR(head, funcToCall);
	cout << endl;
}

void BinarySearchTree::printPostOrder(const function<int(string, int)> &funcToCall)
{
	printPostOrderR(head, funcToCall);
	cout << endl;
}

void BinarySearchTree::printPreOrder(const function<int(string, int)> &funcToCall)
{
	printPreOrderR(head, funcToCall);
	cout << endl;
}

int BinarySearchTree::findHeight(string dataOfNode, int currentHeight)
{
	int nodeHeight = 0;
	bool dataFound = false;

	nodeHeight = findHeightR(head, dataOfNode, dataFound, currentHeight);

	//The function is off by one only if its not zero
	if (nodeHeight > 0)
	{
		++nodeHeight;
	}

	return nodeHeight;
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

void BinarySearchTree::printInOrderR(Node * currentNode, const function<int(string, int)> &funcToCall)
{
	if (currentNode != NULL)
	{
		printInOrderR(currentNode->leftChild, funcToCall);
		cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
		printInOrderR(currentNode->rightChild, funcToCall);
	}
}

void BinarySearchTree::printPostOrderR(Node* currentNode, const function<int(string, int)> &funcToCall)
{
	if (currentNode != NULL)
	{
		printInOrderR(currentNode->leftChild, funcToCall);
		printInOrderR(currentNode->rightChild, funcToCall);
		cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
	}
}

void BinarySearchTree::printPreOrderR(Node* currentNode, const function<int(string, int)> &funcToCall)
{
	if (currentNode != NULL)
	{
		cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
		printInOrderR(currentNode->leftChild, funcToCall);
		printInOrderR(currentNode->rightChild, funcToCall);
	}
}

//Figure out why height get incresly off
int BinarySearchTree::findHeightR(Node* currentNode, const string &dataOfNode, bool& dataFound, int& currentHeight)
{
	if (currentNode == NULL)
	{
		return currentHeight;
	}

	if (currentNode->data == dataOfNode || dataFound == true)
	{
		dataFound = true;
		return currentHeight;
	}
	else
	{
		currentHeight++;
	}

	findHeightR(currentNode->leftChild, dataOfNode, dataFound, currentHeight);
	findHeightR(currentNode->rightChild, dataOfNode, dataFound, currentHeight);

	return currentHeight;
}
