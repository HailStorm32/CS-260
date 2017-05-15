/*
Author: Demetri Van Sickle
Date: 5/12/17
IDE: Visual Studio 2015
Program: Main.cpp
Description:
		Test the BinarySearchTree class
*/

#include "BinarySearchTree.h"

void printNode(const string &dataOfNode, int height);

void main()
{
	cout << "CS260, A5-Binary Trees" << endl;
	cout << "Author: Demetri Van Sickle\n\n" << endl;

	BinarySearchTree tree1;

	
	tree1.insert("T");
	tree1.insert("A");
	tree1.insert("F");
	tree1.insert("Y");
	tree1.insert("R");
	tree1.insert("C");
	//tree1.insert("S");

	/*cout << tree1.findHeight("T") << endl;
	cout << tree1.findHeight("F") << endl;
	cout << tree1.findHeight("C") << endl;
	cout << tree1.findHeight("R") << endl;
	cout << tree1.findHeight("S") << endl;*/

	/*tree1.insert("Jynx");
	tree1.insert("Charmander");
	tree1.insert("Snorlax");
	tree1.insert("Diglett");
	tree1.insert("Kakuna");
	tree1.insert("Meowth");
	tree1.insert("Pikachu");
	tree1.insert("Blastoise");
	tree1.insert("Squirtle");
	tree1.insert("Ivysaur");
	tree1.insert("Bulbasaur");
	tree1.insert("Abra");*/

	cout << "\nPreOrder:" << endl;
	tree1.traversePreOrder(printNode);

	cout << "\nInOrder:" << endl;
	tree1.traverseInOrder(printNode);

	cout << "\nPostOrder:" << endl;
	tree1.traversePostOrder(printNode);

	//Allow console to stay open
	cin.get();
	cin.ignore();
}

void printNode(const string & dataOfNode, int height)
{
	if (height < 0)
	{
		height = 0;
	}

	cout << dataOfNode << "(" << height << ") ";
}