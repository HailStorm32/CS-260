#pragma once
/*
Author: Demetri Van Sickle
Date: 5/12/17
IDE: Visual Studio 2015
Program: Main.cpp
Description:
		Contains the implementation code for the BinarySearchTree class
*/

#include <iostream>
#include <string>

using namespace std;


class BinarySearchTree
{
public:
	BinarySearchTree();

	~BinarySearchTree();

	/*
	Input:
	string -- no empty string
	Return:
	true -- string inserted
	false -- string NOT inserted
	*/
	bool insert(string dataToInsert);

	void printInOrder();

	void printPostOrder();

	void printPreOrder();

private:
	struct Node
	{
		string data;
		Node* leftChild;
		Node* rightChild;
	};

	Node* head;

	unsigned int itemsInTree;

	bool insertRight(const string& dataToInsert, const string& dataInSlot) const;

	void printInOrderR(Node* currentNode);

	void printPostOrderR(Node* currentNode);

	void printPreOrderR(Node* currentNode);
};