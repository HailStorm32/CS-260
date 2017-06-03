/*
Author: Demetri Van Sickle
Date: 6/2/17
IDE: Visual Studio 2015
Program: Sorter.cpp
*/

#include "Sorter.h"

Sorter::Sorter()
{
	//Setup the arrays
	cout << "Setting up arrays..." << endl;

	setupDataArrays(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
	setupDataArrays(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
	setupDataArrays(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
	setupDataArrays(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
	setupDataArrays(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);

	cout << "Setup Done." << endl;
}

Sorter::~Sorter()
{
}

void Sorter::setupDataArrays(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
	int numOfSlotsFilled = 0;
	int indxToFill = 0;
	
	srand(42);//Set the seed for the randomizer

	cout << ARRAY_SIZE << "...";
	
	//Setup the array in normal order
	for (int indx = 0; indx < ARRAY_SIZE; indx++)
	{
		normal[indx] = indx;
	}

	//Setup the array in reverse order
	for (int indx = ARRAY_SIZE; indx != 0; indx--)
	{
		reverse[indx-1] = ARRAY_SIZE - indx;
	}

	//Setup the array in random order

	//First set the array to -1
	//This will enable us to not fill the same indx twice
	for (int indx = 0; indx < ARRAY_SIZE; indx++)
	{
		random[indx] = -1;
	}

	for (int indx = 0; indx < ARRAY_SIZE; indx++)
	{
		random[indx] = rand() % ARRAY_SIZE;
	}

	/*while (numOfSlotsFilled != ARRAY_SIZE - 1)
	{
		indxToFill = rand() % ARRAY_SIZE;//Get the the array indx to fill

		//Only fill the indx if there already isnt data in it
		if (random[indxToFill] == -1)
		{
			random[indxToFill] = numOfSlotsFilled;

			numOfSlotsFilled++;
		}
		cout << numOfSlotsFilled << endl;
	}*/
	cout << " ...Done." << endl;
}
