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
	cout << "\nnormalTime: " << dSet100->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet100->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet100->timeToSortRandBubble << " seconds." << endl;

	cout << "\nSelection Sorting 100..." << endl;
	selectionSort(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet100->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet100->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet100->timeToSortRandSelection << " seconds." << endl;

	cout << "\nQuick Sorting 100..." << endl;
	quickSort(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet100->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet100->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet100->timeToSortRandSelection << " seconds." << endl;

	cout << "============================================================" << endl;
	cout << "============================================================" << endl;

	cout << "\nBubble Sorting 1K..." << endl;
	bubbleSort(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1K->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet1K->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet1K->timeToSortRandBubble << " seconds." << endl;

	cout << "\nSelection Sorting 1K..." << endl;
	selectionSort(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet1K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet1K->timeToSortRandSelection << " seconds." << endl;

	cout << "\nQuick Sorting 1K..." << endl;
	quickSort(dSet1K->normal, dSet1K->reverse, dSet1K->random, dSet1K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet1K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet1K->timeToSortRandSelection << " seconds." << endl;

	cout << "============================================================" << endl;
	cout << "============================================================" << endl;

	cout << "\nBubble Sorting 10K..." << endl;
	bubbleSort(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet10K->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet10K->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet10K->timeToSortRandBubble << " seconds." << endl;

	cout << "\nSelection Sorting 10K..." << endl;
	selectionSort(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet10K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet10K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet10K->timeToSortRandSelection << " seconds." << endl;

	cout << "\nQuick Sorting 10K..." << endl;
	quickSort(dSet10K->normal, dSet10K->reverse, dSet10K->random, dSet10K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet10K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet10K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet10K->timeToSortRandSelection << " seconds." << endl;

	cout << "============================================================" << endl;
	cout << "============================================================" << endl;

	cout << "\nBubble Sorting 100K..." << endl;
	bubbleSort(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet100K->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet100K->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet100K->timeToSortRandBubble << " seconds." << endl;

	cout << "\nSelection Sorting 100K..." << endl;
	selectionSort(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet100K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet100K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet100K->timeToSortRandSelection << " seconds." << endl;

	cout << "\nQuick Sorting 100K..." << endl;
	quickSort(dSet100K->normal, dSet100K->reverse, dSet100K->random, dSet100K->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet100K->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet100K->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet100K->timeToSortRandSelection << " seconds." << endl;

	cout << "============================================================" << endl;
	cout << "============================================================" << endl;

	cout << "\nBubble Sorting 1M..." << endl;
	bubbleSort(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1M->timeToSortNormBubble << " seconds." << endl;
	cout << "reverseTime: " << dSet1M->timeToSortRevBubble << " seconds." << endl;
	cout << "randomTime: " << dSet1M->timeToSortRandBubble << " seconds." << endl;

	cout << "\nSelection Sorting 1M..." << endl;
	selectionSort(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1M->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet1M->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet1M->timeToSortRandSelection << " seconds." << endl;

	cout << "\nQuick Sorting 1M..." << endl;
	quickSort(dSet1M->normal, dSet1M->reverse, dSet1M->random, dSet1M->ARRAY_SIZE);
	cout << "\nnormalTime: " << dSet1M->timeToSortNormSelection << " seconds." << endl;
	cout << "reverseTime: " << dSet1M->timeToSortRevSelection << " seconds." << endl;
	cout << "randomTime: " << dSet1M->timeToSortRandSelection << " seconds." << endl;

	//quickSort(dSet100->normal, dSet100->reverse, dSet100->random, dSet100->ARRAY_SIZE);

}

void Sorter::printToFile(const string FILE_NAME)
{
	fileWrite.open(FILE_NAME);

	if (!fileWrite.is_open())
	{
		cout << "\n\n ERROR! Cant open file! " << FILE_NAME << endl;
	}

	cout << "\nWriting to file...";

	fileWrite << "Bubble Sort, 100, 1000, 10000, 100000, 1000000" << endl;
	fileWrite << "In Order, " << dSet100->timeToSortNormBubble << ", " << dSet1K->timeToSortNormBubble << ", " << dSet10K->timeToSortNormBubble << ", " 
		<< dSet100K->timeToSortNormBubble << ", " << dSet1M->timeToSortNormBubble << endl;
	fileWrite << "Reverse Order, " << dSet100->timeToSortRevBubble << ", " << dSet1K->timeToSortRevBubble << ", " << dSet10K->timeToSortRevBubble << ", "
		<< dSet100K->timeToSortRevBubble << ", " << dSet1M->timeToSortRevBubble << endl;
	fileWrite << "Random, " << dSet100->timeToSortRandBubble << ", " << dSet1K->timeToSortRandBubble << ", " << dSet10K->timeToSortRandBubble << ", "
		<< dSet100K->timeToSortRandBubble << ", " << dSet1M->timeToSortRandBubble << endl;

	fileWrite << ", , , , ,\n, , , , ," << endl;

	fileWrite << "Selection Sort, 100, 1000, 10000, 100000, 1000000" << endl;
	fileWrite << "In Order, " << dSet100->timeToSortNormSelection << ", " << dSet1K->timeToSortNormSelection << ", " << dSet10K->timeToSortNormSelection << ", "
		<< dSet100K->timeToSortNormSelection << ", " << dSet1M->timeToSortNormSelection << endl;
	fileWrite << "Reverse Order, " << dSet100->timeToSortRevSelection << ", " << dSet1K->timeToSortRevSelection << ", " << dSet10K->timeToSortRevSelection << ", "
		<< dSet100K->timeToSortRevSelection << ", " << dSet1M->timeToSortRevSelection << endl;
	fileWrite << "Random, " << dSet100->timeToSortRandSelection << ", " << dSet1K->timeToSortRandSelection << ", " << dSet10K->timeToSortRandSelection << ", "
		<< dSet100K->timeToSortRandSelection << ", " << dSet1M->timeToSortRandSelection << endl;

	fileWrite << ", , , , ,\n, , , , ," << endl;

	fileWrite << "Quick Sort, 100, 1000, 10000, 100000, 1000000" << endl;
	fileWrite << "In Order, " << dSet100->timeToSortNormQuick << ", " << dSet1K->timeToSortNormQuick << ", " << dSet10K->timeToSortNormQuick << ", "
		<< dSet100K->timeToSortNormQuick << ", " << dSet1M->timeToSortNormQuick << endl;
	fileWrite << "Reverse Order, " << dSet100->timeToSortRevQuick << ", " << dSet1K->timeToSortRevQuick << ", " << dSet10K->timeToSortRevQuick << ", "
		<< dSet100K->timeToSortRevQuick << ", " << dSet1M->timeToSortRevQuick << endl;
	fileWrite << "Random, " << dSet100->timeToSortRandQuick << ", " << dSet1K->timeToSortRandQuick << ", " << dSet10K->timeToSortRandQuick << ", "
		<< dSet100K->timeToSortRandQuick << ", " << dSet1M->timeToSortRandQuick << endl;

	fileWrite.close();

	cout << "...Done." << endl;
}

void Sorter::setupDataArrays(int normal[], int reverse[], int random[], const int ARRAY_SIZE)
{
	int numOfSlotsFilled = 0;
	int indxToFill = 0;

	srand(42);//Set the seed for the randomizer

	//cout << ARRAY_SIZE << "...";

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
	//cout << " ...Done." << endl;
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
	float normalTime;
	float reverseTime;
	float randomTime;

	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
	cout << normal[indx2] << " ";
	}
	cout << "\n";*/
	cout << "normal..." << endl;
	clock1 = clock();
	quickSortR(normal, 0, ARRAY_SIZE - 1);
	normalTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;
	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << normal[indx2] << " ";
	}
	cout << "\n";*/

	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << reverse[indx2] << " ";
	}
	cout << "\n";*/
	cout << "reverse..." << endl;
	clock1 = clock();
	quickSortR(reverse, 0, ARRAY_SIZE - 1);
	reverseTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;
	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << reverse[indx2] << " ";
	}
	cout << "\n";*/

	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << random[indx2] << " ";
	}
	cout << "\n";*/
	cout << "random..." << endl;
	clock1 = clock();
	quickSortR(random, 0, ARRAY_SIZE - 1);
	randomTime = static_cast<float>(clock() - clock1) / CLOCKS_PER_SEC;
	/*cout << "\n";
	for (int indx2 = 0; indx2 < ARRAY_SIZE; indx2++)
	{
		cout << random[indx2] << " ";
	}*/

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

void Sorter::quickSortR(int array[], int leftPointer, int rightPointer)
{
	int pivot = array[(leftPointer + rightPointer) / 2];
	int indx = 0;

	if (leftPointer >= rightPointer)
	{
		return;
	}

	indx = split(array, leftPointer, rightPointer, pivot);

	quickSortR(array, leftPointer, indx - 1);
	quickSortR(array, indx, rightPointer);
}

int Sorter::split(int array[], int leftPointer, int rightPointer, int pivot)
{
	//While the pointers havn't passed each other
	while (leftPointer <= rightPointer)
	{
		//Continue to increment the left pointer until we hit a value greater than the pivot
		while (array[leftPointer] < pivot && leftPointer < rightPointer)
		{
			leftPointer++;
		}

		//Continue to decrement the left pointer until we hit a value greater than the pivot
		while (array[rightPointer] >= pivot && rightPointer > leftPointer)
		{
			rightPointer--;
		}

		//Swap the two values, and move the pointers
		swap(array, leftPointer, rightPointer);
		leftPointer++;
		rightPointer--;
	}
	return leftPointer;
}

void Sorter::swap(int array[], int indx1, int indx2)
{
	int indx1Value;

	indx1Value = array[indx1];

	array[indx1] = array[indx2];

	array[indx2] = indx1Value;
}
