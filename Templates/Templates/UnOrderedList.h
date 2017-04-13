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

	~UnOrderedList()
	{

	}

	bool prepend(int dataToEnter)
	{
		//Make sure item is not already in the list
		if (find(dataToEnter) > 0)
		{
			return false;
		}

		Node* newNode = new Node;
		Node* currentNode = NULL;
		//Node* prevNode = NULL;

		newNode->data = dataToEnter;
		newNode->nextNodeAddress = NULL;

		//If first item in the list
		if (head == NULL)
		{
			head = newNode;

			itemsInList++;

			return true;
		}
		else
		{
			currentNode = head;

			head = newNode;

			newNode->nextNodeAddress = currentNode;

			itemsInList++;

			return true;
		}
	}

	bool append(int dataToEnter)
	{
		//Make sure item is not already in the list
		if (find(dataToEnter) > 0)
		{
			return false;
		}

		Node* currentNode = NULL;
		
		//Setup new node
		Node* newNode = new Node;
		newNode->data = dataToEnter;
		newNode->nextNodeAddress = NULL;

		//If first item in the list
		if (head == NULL)
		{
			head = newNode;

			itemsInList++;
			
			return true;
		}
		else
		{
			currentNode = head;

			//Find the last node
			while (currentNode->nextNodeAddress != NULL)
			{
				currentNode = currentNode->nextNodeAddress;
			}

			//Point the last node to the new node
			currentNode->nextNodeAddress = newNode;
			
			itemsInList++;

			return true;
		}
	}

	int find(int dataToFind) const
	{	
		Node* currentNode = NULL;
		unsigned int itemPos = 1;

		currentNode = head;

		while (currentNode != NULL)
		{
			if (dataToFind == currentNode->data)
			{
				return itemPos;
			}
			else
			{
				currentNode = currentNode->nextNodeAddress;
				itemPos++;
			}
		}

		//If we got this far that means there was no match
		return 0;
	}

	bool remove(int itemToRemove)
	{
		unsigned int indx = 1;
		unsigned int itemLocation;
		Node* currentNode = NULL;
		Node* prevNode = NULL;

		itemLocation = find(itemToRemove);
		
		if (itemLocation == 0)
		{
			return false;
		}

		currentNode = head;

		//Go to items location
		while (indx < itemLocation)
		{
			prevNode = currentNode;
			currentNode = currentNode->nextNodeAddress;
			indx++;
		}

		//If there was only one item in the list
		if (itemsInList == 1)
		{
			delete currentNode;
			itemsInList--;
			head = NULL;
			return true;
		}

		if (itemLocation == 1)
		{
			head = currentNode->nextNodeAddress;
			delete currentNode;
			itemsInList--;
			return true;
		}
		
		//If item is the last item in the list
		if (itemsInList == itemLocation)
		{
			delete currentNode;
			itemsInList--;
			prevNode->nextNodeAddress = NULL;
			return true;
		}

		//If item is somewhere else in the list
		prevNode->nextNodeAddress = currentNode->nextNodeAddress;
		delete currentNode;
		itemsInList--;
		return true;
	}

	void print() const
	{
		Node* currentNode = NULL;

		if (head == NULL)
		{
			cout << "The list is empty" << endl;
			return;
		}

		cout << "The list contains the following " << itemsInList << " elements:" << endl;

		currentNode = head;

		while (currentNode->nextNodeAddress != NULL)
		{
			cout << currentNode->data << ", ";
			currentNode = currentNode->nextNodeAddress;
		}
		cout << currentNode->data << endl;
	}

	void removeAll()
	{
		Node* currentNode = NULL;
		Node* nodeToDelete = NULL;

		currentNode = head;

		while (currentNode != NULL)
		{
			nodeToDelete = currentNode;
			currentNode = currentNode->nextNodeAddress;
			delete nodeToDelete;
		}

		head = NULL;
		itemsInList = 0;
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