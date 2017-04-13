/*
Program: templateTest.cpp
Author: Demetri Van Sickle
Date: 4/12/17
IDE: Visual Studio 2015
Description:
	Test the LinkedList class
*/

#include <iostream>
#include "UnOrderedList.h"

using namespace std;

void main()
{
	UnOrderedList list1;

	list1.append(10);
	list1.append(4);
	list1.append(7);
	list1.prepend(44);
	
	list1.print();

	list1.remove(4);

	list1.print();

	list1.remove(44);

	list1.print();

	list1.removeAll();

	list1.print();

	list1.append(456);

	list1.print();
}