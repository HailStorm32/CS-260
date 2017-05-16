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

		itemsInTree++;
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
		itemsInTree++;
	}
	else
	{
		prevNode->leftChild = newNode;
		itemsInTree++;
	}

	return true;
}

void BinarySearchTree::traverseInOrder(const function<void(string, int)> &funcToCall)
{
	traverseInOrderR(head, funcToCall, 0);
	cout << endl;
}

void BinarySearchTree::traversePostOrder(const function<void(string, int)> &funcToCall)
{
	traversePostOrderR(head, funcToCall, 0);
	cout << endl;
}

void BinarySearchTree::traversePreOrder(const function<void(string, int)> &funcToCall)
{
	traversePreOrderR(head, funcToCall, 0);
	cout << endl;
}

bool BinarySearchTree::deleteNode(const string dataToDelete)
{
	bool dataFound = false;
	Node* nodeToDelete = NULL;
	Node* prevNode = NULL;

	findNodeR(head, dataToDelete, nodeToDelete, prevNode, dataFound);

	if (nodeToDelete == NULL)
	{
		cout << "ERROR" << endl;
		return false;
	}

	//Debug only
	cout << "Node to delete: " << nodeToDelete->data << endl;
	cout << "Prev node: " << prevNode->data << endl;

	return true;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

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

void BinarySearchTree::traverseInOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height)
{
	if (currentNode != NULL)
	{
		traverseInOrderR(currentNode->leftChild, funcToCall, ++height);
		//cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
		funcToCall(currentNode->data, --height);
		traverseInOrderR(currentNode->rightChild, funcToCall, ++height);
	}
	else
	{
		--height;
	}
}

void BinarySearchTree::traversePostOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height)
{
	int originalHeight = 0;

	if (currentNode != NULL)
	{
		originalHeight = height;
		traversePostOrderR(currentNode->leftChild, funcToCall, ++height);
		height = originalHeight;
		traversePostOrderR(currentNode->rightChild, funcToCall, ++height);
		funcToCall(currentNode->data, --height);
		//cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
	}
}

void BinarySearchTree::traversePreOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height)
{
	int originalHeight = 0;

	if (currentNode != NULL)
	{
		//cout << currentNode->data << "(" << funcToCall(currentNode->data, 0) << ")" << " ";
		originalHeight = height;
		funcToCall(currentNode->data, height);
		traversePreOrderR(currentNode->leftChild, funcToCall, ++height);
		height = originalHeight;
		traversePreOrderR(currentNode->rightChild, funcToCall, ++height);
	}
}

void BinarySearchTree::findNodeR(Node * currentNode, const string& dataOfNode, Node *& foundAddress, Node *& prevAddress, bool& dataFound)
{
	if (currentNode == NULL)
	{
		return;
	}

	if (currentNode->data == dataOfNode)
	{
		dataFound = true;

		foundAddress = currentNode;
		return;
	}
	
	if (dataFound != true)
	{
		prevAddress = currentNode;

		findNodeR(currentNode->leftChild, dataOfNode, foundAddress, prevAddress, dataFound);

		prevAddress = currentNode;

		findNodeR(currentNode->rightChild, dataOfNode, foundAddress, prevAddress, dataFound);
	}
	else
	{
		return;
	}
}
