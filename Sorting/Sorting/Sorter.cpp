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

void Sorter::startSortingAll()
{
	cout << "\nBubble Sorting 100..." << endl;
	bubbleSort(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
	//cout << "...Done!\n" << endl;

	cout << "\nnormalTime: " << dSet100->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet100->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet100->timeToSortRandBubble << " seconds." << endl;

	cout << "\nselection Sorting 100..." << endl;
	selectionSort(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);

	cout << "\nnormalTime: " << dSet100->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet100->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet100->timeToSortRandSelection << " seconds." << endl;
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
		reverse[indx - 1] = ARRAY_SIZE - indx;
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
	float normalTime;
	float reverseTime;
	float randomTime;

	cout << "normal..." << endl;
	clock1 = clock();
	bubbleSortR(normal, ARRAY_SIZE);
	normalTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	cout << "reverse..." << endl;
	clock1 = 0;
	clock1 = clock();
	bubbleSortR(reverse, ARRAY_SIZE);
	reverseTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	

	cout << "random..." << endl;
	clock1 = clock();
	bubbleSortR(random, ARRAY_SIZE);
	randomTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	switch (ARRAY_SIZE)
	{
	case 100:
		dSet100->timeToSortNormBubble = normalTime;
		dSet100->timeToSortRevBubble = reverseTime;
		dSet100->timeToSortRandBubble = randomTime;
		setupDataArrays(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
		break;
	case 1000:
		dSet1K->timeToSortNormBubble = normalTime;
		dSet1K->timeToSortRevBubble = reverseTime;
		dSet1K->timeToSortRandBubble = randomTime;
		setupDataArrays(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
		break;
	case 10000:
		dSet10K->timeToSortNormBubble = normalTime;
		dSet10K->timeToSortRevBubble = reverseTime;
		dSet10K->timeToSortRandBubble = randomTime;
		setupDataArrays(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
		break;
	case 100000:
		dSet100K->timeToSortNormBubble = normalTime;
		dSet100K->timeToSortRevBubble = reverseTime;
		dSet100K->timeToSortRandBubble = randomTime;
		setupDataArrays(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
		break;
	case 1000000:
		dSet1M->timeToSortNormBubble = normalTime;
		dSet1M->timeToSortRevBubble = reverseTime;
		dSet1M->timeToSortRandBubble = randomTime;
		setupDataArrays(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);
		break;
	}
}

void Sorter::bubbleSortR(int array[], const int ARRAY_SIZE)
{
	bool isSorted = false;

	////DEBUG//////////////
	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << array[indx2] << " ";
	}*/
	////DEBUG//////////////

	//Continue to cycle through the array until the sorted flag isnt triggered
	while (isSorted == false)
	{
		isSorted = true;


		for (int indx2 = 0; indx2 < ARRAY_SIZE - 1; indx2++)
		{
			//If the the adj indx is in the wrong spot, swap it and trigger the flag
			if (array[indx2] > array[indx2 + 1])
			{
				isSorted = false;
				swap(array, indx2, indx2 + 1);
			}
		}
	}

	////DEBUG//////////////
	/*cout << "\n\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << array[indx2] << " ";
	}
	cout << "\n";*/
	////DEBUG//////////////
}

void Sorter::selectionSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
	float normalTime;
	float reverseTime;
	float randomTime;

	cout << "normal..." << endl;
	clock1 = clock();
	selectionSortR(normal, ARRAY_SIZE);
	normalTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	cout << "reverse..." << endl;
	clock1 = clock();
	selectionSortR(reverse, ARRAY_SIZE);
	reverseTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	cout << "random..." << endl;
	clock1 = clock();
	selectionSortR(random, ARRAY_SIZE);
	randomTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;

	switch (ARRAY_SIZE)
	{
	case 100:
		dSet100->timeToSortNormSelection = normalTime;
		dSet100->timeToSortRevSelection = reverseTime;
		dSet100->timeToSortRandSelection = randomTime;
		setupDataArrays(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
		break;
	case 1000:
		dSet1K->timeToSortNormSelection = normalTime;
		dSet1K->timeToSortRevSelection = reverseTime;
		dSet1K->timeToSortRandSelection = randomTime;
		setupDataArrays(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
		break;
	case 10000:
		dSet10K->timeToSortNormSelection = normalTime;
		dSet10K->timeToSortRevSelection = reverseTime;
		dSet10K->timeToSortRandSelection = randomTime;
		setupDataArrays(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
		break;
	case 100000:
		dSet100K->timeToSortNormSelection = normalTime;
		dSet100K->timeToSortRevSelection = reverseTime;
		dSet100K->timeToSortRandSelection = randomTime;
		setupDataArrays(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
		break;
	case 1000000:
		dSet1M->timeToSortNormSelection = normalTime;
		dSet1M->timeToSortRevSelection = reverseTime;
		dSet1M->timeToSortRandSelection = randomTime;
		setupDataArrays(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);
		break;
	}

}

void Sorter::selectionSortR(int array[], const int ARRAY_SIZE)
{
	int smallestInxVal = 0;
	bool isSorted = false;
	int indxOffSet = 0;//where the "unsorted" array begins

	//Continue to cycle through the array until the sorted flag isnt triggered
	while (isSorted == false)
	{
		isSorted = true;

		//Find the smallest value
		for (int indx = indxOffSet; indx < ARRAY_SIZE; indx++)
		{
			if (array[indx] < array[smallestInxVal])
			{
				smallestInxVal = indx;
				isSorted = false;
			}
		}

		//Swap the smallest value and the beginning of the "unsorted" array
		swap(array, smallestInxVal, indxOffSet);

		//Make our "sorted" array larger
		indxOffSet++;
	}
}

void Sorter::quickSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{

}

void Sorter::swap(int array[], int indx1, int indx2)
{
	int indx1Value;

	indx1Value = array[indx1];

	array[indx1] = array[indx2];

	array[indx2] = indx1Value;
}
