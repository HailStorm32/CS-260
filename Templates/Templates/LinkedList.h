#pragma once
#include <iostream>

using namespace std;

class UnOrderedList
{
public:
	UnOrderedList()
	{
		head = NULL;
		itemsInList = 0;
	}

	bool prepend(int dataToEnter)
	{
		//check duplicate here

		Node* newNode = new Node;
		Node* currentNode = NULL;
		Node* prevNode = NULL;

		if (head == NULL)
		{

		}
	}

private:
	struct Node
	{
		int data;
		Node* nextNodeAddress;
	};

	unsigned int itemsInList;

	Node* head;
};