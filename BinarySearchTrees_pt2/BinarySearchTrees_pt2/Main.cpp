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
	BinarySearchTree* tree2;


	tree1.insert("Jynx");
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
	tree1.insert("Abra");

	cout << "\nPrinting tree in alphabetical order:" << endl;
	tree1.traverseInOrder(printNode);

	cout << "\nMaking deep copy of tree.." << endl;
	tree2 = tree1.deepCopy();

	cout << "\nDeleting Squirtle and printing:" << endl;
	tree1.deleteNode("Squirtle");
	tree1.traverseInOrder(printNode);

	cout << "\nDeleting Meowth and printing:" << endl;
	tree1.deleteNode("Meowth");
	tree1.traverseInOrder(printNode);

	cout << "\nDeleting Blastoise and printing:" << endl;
	tree1.deleteNode("Blastoise");
	tree1.traverseInOrder(printNode);

	cout << "\nDeleting Jynx and printing:" << endl;
	tree1.deleteNode("Jynx");
	tree1.traverseInOrder(printNode);

	cout << "\nPrinting copy of tree inOrder:" << endl;
	tree2->traverseInOrder(printNode);

	cout << "\nPostOrder:" << endl;
	tree2->traversePostOrder(printNode);

	cout << "\nand PreOrder:" << endl;
	tree2->traversePreOrder(printNode);

	cout << "\nDeleting the copy tree..." << endl;
	tree2->deleteAll();

	cout << "\nPrinting the copy tree:" << endl;
	tree2->traverseInOrder(printNode);


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