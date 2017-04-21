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

	list1.insert("Bob");
	list1.insert("David");
	list1.insert("Alice");
	list1.insert("Edward");
	list1.insert("Claire");

	cout << "Forward:" << endl;
	list1.print(false);

	cout << "\nBackward:" << endl;
	list1.print(true);

	list1.insert("Bob");
	list1.insert("Edward");
	list1.insert("Claire");
	list1.insert("Claire");

	cout << "\nAlice shows up " << list1.find("Alice") << " time(s) in this list." << endl;
	cout << "\nBob shows up " << list1.find("Bob") << " time(s) in this list." << endl;
	cout << "\nClaire shows up " << list1.find("Claire") << " time(s) in this list." << endl;
	cout << "\nEdward shows up " << list1.find("Edward") << " time(s) in this list." << endl;

	cout << "\nThe letter 'e' shows up " << list1.findLetter('e') << " times in this list." << endl;

	list1.remove("David");
	/*list1.remove("Alice");
	list1.remove("Edward");*/

	cout << "\nForward:" << endl;
	list1.print(false);

	cout << "\nBackward:" << endl;
	list1.print(true);

	//Allow console to stay open
	cin.get();
	cin.ignore();

}