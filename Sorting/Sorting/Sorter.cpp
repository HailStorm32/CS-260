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

	dSet100->timeToSortNorm = 0;
	dSet100->timeToSortRev = 0;
	dSet100->timeToSortRand = 0;

	dSet1K->timeToSortNorm = 0;
	dSet1K->timeToSortRev = 0;
	dSet1K->timeToSortRand = 0;

	dSet10K->timeToSortNorm = 0;
	dSet10K->timeToSortRev = 0;
	dSet10K->timeToSortRand = 0;

	dSet100K->timeToSortNorm = 0;
	dSet100K->timeToSortRev = 0;
	dSet100K->timeToSortRand = 0;

	dSet1M->timeToSortNorm = 0;
	dSet1M->timeToSortRev = 0;
	dSet1M->timeToSortRand = 0;

	cout << "Setup Done." << endl;
}

Sorter::~Sorter()
{
}

void Sorter::startSortingAll()
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
	cout << " ...Done." << endl;
}

void Sorter::bubbleSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
	bool sorted = false;
	
	while (sorted == false)
	{
		sorted == true;

		for (int indx = 0; indx < ARRAY_SIZE-1; indx++)
		{
			if (normal[indx] < normal[indx + 1])
			{

			}
		}
	}
}

void Sorter::mergeSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
}

void Sorter::quickSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
}
