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
#include <functional>

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

	void printInOrder(const function<int(string, int)> &funcToCall);

	void printPostOrder(const function<int(string, int)> &funcToCall);

	void printPreOrder(const function<int(string, int)> &funcToCall);

	int findHeight(string dataOfNode, int currentHeight = 0);

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

	void printInOrderR(Node* currentNode, const function<int(string, int)> &funcToCall);

	void printPostOrderR(Node* currentNode, const function<int(string, int)> &funcToCall);

	void printPreOrderR(Node* currentNode, const function<int(string, int)> &funcToCall);

	int findHeightR(Node* currentNode, const string &dataOfNode, bool& dataFound, int& currentHeight);
};