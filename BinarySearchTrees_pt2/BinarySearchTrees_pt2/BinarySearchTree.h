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

	void traverseInOrder(const function<void(string, int)> &funcToCall);

	void traversePostOrder(const function<void(string, int)> &funcToCall);

	void traversePreOrder(const function<void(string, int)> &funcToCall);

	bool deleteNode(const string dataToDelete);

	BinarySearchTree* deepCopy();

	void deleteAll();


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

	void traverseInOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height);

	void traversePostOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height);

	void traversePreOrderR(Node* currentNode, const function<void(string, int)> &funcToCall, int height);

	void traversePreOrderR(Node* currentNode, BinarySearchTree* newTreePointer);

	void findNodeR(Node* currentNode, const string &dataOfNode, Node* &foundAddress, Node* &prevAddress, bool& dataFound);

	void findNodeR(Node* currentNode, const string &dataOfNode, bool& dataFound);

	void insertCopy(string dataToInsert, BinarySearchTree * newTreePointer);

	void deleteAllR(Node* currentNode);
};