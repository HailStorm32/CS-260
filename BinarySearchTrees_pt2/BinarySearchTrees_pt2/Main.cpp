/*
Author: Demetri Van Sickle
Date: 5/12/17
IDE: Visual Studio 2015
Program: Main.cpp
Description:
		Test the BinarySearchTree class
*/

#include "BinarySearchTree.h"

void main()
{
	cout << "Author: Demetri Van Sickle\n\n" << endl;

	BinarySearchTree tree1;

	tree1.insert("Jynx");
	tree1.insert("Charmander");
	tree1.insert("Snorlax");
	tree1.insert("Clefairy");
	tree1.insert("Diglett");
	tree1.insert("Kakuna");
	tree1.insert("Meowth");
	tree1.insert("Nidorino");
	tree1.insert("Pikachu");
	tree1.insert("Blastoise");
	tree1.insert("Squirtle");
	tree1.insert("Ivysaur");
	tree1.insert("Bulbasaur");
	tree1.insert("Abra");

	cout << "\nPreOrder:" << endl;
	tree1.printPreOrder();

	cout << "\nInOrder:" << endl;
	tree1.printInOrder();

	cout << "\nPostOrder:" << endl;
	tree1.printPostOrder();

	//Allow console to stay open
	cin.get();
	cin.ignore();
}