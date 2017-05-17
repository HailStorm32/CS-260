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
	bool dataFound = false;
	
	//Make sure string isnt empty
	if (dataToInsert.empty())
	{
		return false;
	}

	//See if data isnt already in the tree
	findNodeR(head, dataToInsert, dataFound);
	if (dataFound == true)
	{
		cout << "Error! Data already in tree!" << endl;
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
	Node* currentNode = NULL;
	Node* tempPointerHolder = NULL;
	string tempValueHolder = "";

	if (head == NULL)
	{
		cout << "Tree already empty" << endl;
		return false;
	}

	//Find the node we want to delete, and get its address
	findNodeR(head, dataToDelete, nodeToDelete, prevNode, dataFound);

	//Debug only
	//cout << "Node to delete: " << nodeToDelete->data << endl;
	//cout << "Prev node: " << prevNode->data << endl;

	//If leaf Node
	if (nodeToDelete->leftChild == NULL && nodeToDelete->rightChild == NULL)
	{
		//If this node was on right of parent node
		if (nodeToDelete->data > prevNode->data)
		{
			delete nodeToDelete;
			itemsInTree--;
			
			//set parent's pointer to null
			prevNode->rightChild = NULL;
		}
		//If this node was to the left of the parent node
		else
		{
			delete nodeToDelete;
			itemsInTree--;

			//set parent's pointer to null
			prevNode->rightChild = NULL;
		}
	}
	//If node only has a left child
	else if (nodeToDelete->leftChild != NULL && nodeToDelete->rightChild == NULL)
	{
		//If this node was on right of parent node
		if (nodeToDelete->data > prevNode->data)
		{
			prevNode->rightChild = nodeToDelete->leftChild;
			delete nodeToDelete;
			itemsInTree--;
		}
		//If this node was to the left of the parent node
		else
		{
			prevNode->leftChild = nodeToDelete->leftChild;
			delete nodeToDelete;
			itemsInTree--;
		}
	}
	//If node only has right child
	else if (nodeToDelete->leftChild == NULL && nodeToDelete->rightChild != NULL)
	{
		//If this node was on right of parent node
		if (nodeToDelete->data > prevNode->data)
		{
			prevNode->rightChild = nodeToDelete->rightChild;
			delete nodeToDelete;
			itemsInTree--;
		}
		//If this node was to the left of the parent node
		else
		{
			prevNode->leftChild = nodeToDelete->rightChild;
			delete nodeToDelete;
			itemsInTree--;
		}
	}
	//If node has left and right child
	else if (nodeToDelete->leftChild != NULL && nodeToDelete->rightChild != NULL)
	{
		currentNode = nodeToDelete->leftChild;
		
		//Find the largest value on the left of the nodeToDelete by going to the right until we hit a null
		while (currentNode->rightChild != NULL)
		{
			currentNode = currentNode->rightChild;
		}

		tempValueHolder = currentNode->data;

		//Move variables around so that their naming makes more sense 
		tempPointerHolder = nodeToDelete;
		nodeToDelete = currentNode;
		currentNode = tempPointerHolder;

		//Now delete the soon to be duplicate node by calling the deleteNode function on it
		deleteNode(nodeToDelete->data);

		//Replace the nodeToDelete with the biggest node in the left sub-tree
		currentNode->data = tempValueHolder;
	}
	else
	{
		cout << "ERROR! Cant delete node!" << endl;
		return false;
	}

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
		funcToCall(currentNode->data, --height);
		traverseInOrderR(currentNode->rightChild, funcToCall, ++height);
	}
}

void BinarySearchTree::traversePostOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height)
{
	int originalHeight = 0;

	if (currentNode != NULL)
	{
		originalHeight = height;//Reset the height 
		traversePostOrderR(currentNode->leftChild, funcToCall, ++height);
		height = originalHeight;//Reset the height
		traversePostOrderR(currentNode->rightChild, funcToCall, ++height);
		funcToCall(currentNode->data, --height);
	}
}

void BinarySearchTree::traversePreOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height)
{
	int originalHeight = 0;

	if (currentNode != NULL)
	{
		originalHeight = height;//Reset the height
		funcToCall(currentNode->data, height);
		traversePreOrderR(currentNode->leftChild, funcToCall, ++height);
		height = originalHeight;//Reset the height
		traversePreOrderR(currentNode->rightChild, funcToCall, ++height);
	}
}

void BinarySearchTree::findNodeR(Node * currentNode, const string& dataOfNode, Node *& foundAddress, Node *& prevAddress, bool& dataFound)
{
	//Make sure string isnt empty
	if (dataOfNode.empty())
	{
		return;
	}
	
	if (head == NULL || currentNode == NULL)
	{
		return;
	}

	if (currentNode->leftChild != NULL && currentNode->leftChild->data == dataOfNode)
	{
		dataFound = true;
		prevAddress = currentNode;
		foundAddress = currentNode->leftChild;
		return;
	}
	else if (currentNode->rightChild != NULL && currentNode->rightChild->data == dataOfNode)
	{
		dataFound = true;
		prevAddress = currentNode;
		foundAddress = currentNode->rightChild;
		return;
	}

	//Cycle the tree untill we find our node
	if (dataFound != true)
	{
		findNodeR(currentNode->leftChild, dataOfNode, foundAddress, prevAddress, dataFound);
		findNodeR(currentNode->rightChild, dataOfNode, foundAddress, prevAddress, dataFound);
	}
	else
	{
		return;
	}
}

void BinarySearchTree::findNodeR(Node * currentNode, const string & dataOfNode, bool & dataFound)
{
	//Make sure string isnt empty
	if (dataOfNode.empty())
	{
		return;
	}
	
	if (head == NULL || currentNode == NULL)
	{
		return;
	}

	if (currentNode->leftChild != NULL && currentNode->leftChild->data == dataOfNode)
	{
		dataFound = true;
		return;
	}
	else if (currentNode->rightChild != NULL && currentNode->rightChild->data == dataOfNode)
	{
		dataFound = true;
		return;
	}

	//Cycle the tree untill we find our node
	if (dataFound != true)
	{
		findNodeR(currentNode->leftChild, dataOfNode, dataFound);
		findNodeR(currentNode->rightChild, dataOfNode, dataFound);
	}
	else
	{
		return;
	}
}
