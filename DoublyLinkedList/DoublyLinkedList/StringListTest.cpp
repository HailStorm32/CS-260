/*
Program: StingListTest.cpp
Author: Demetri Van Sickle
Date: 4/15/17
IDE: Visual Studio 2015
Program:
	Test the doubly linked list class
*/

#include <iostream>
#include "StringList.h"

using namespace std;

void main()
{
	StringList list1;

	//list1.insert("Bob");
	list1.insert("Apple");
	//list1.insert("Cat");
	list1.insert("Able");
	list1.insert("Able");
	list1.insert("Able");
	list1.insert("Zoo");

	list1.remove("Able");
	list1.remove("Zoo");
	//list1.remove("Cat");
	while(true){}

}