#pragma once
/*
Author: Demetri Van Sickle
Date: 6/2/17
IDE: Visual Studio 2015
Program: Sorter.h
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Sorter
{
public:
	Sorter();

	~Sorter();

	void startSortingAll();

private:
	struct DataSet100
	{
		const int ARRAY_SIZE = 100;

		int normal[100];
		int reverse[100];
		int random[100];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble=0;
		float timeToSortRevSelection =0;
		float timeToSortRevQuick=0;

		float timeToSortRandBubble=0;
		float timeToSortRandSelection =0;
		float timeToSortRandQuick=0;
	};

	struct DataSet1K
	{
		const int ARRAY_SIZE = 1000;

		int normal[1000];
		int reverse[1000];
		int random[1000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct DataSet10K
	{
		const int ARRAY_SIZE = 10000;

		int normal[10000];
		int reverse[10000];
		int random[10000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct DataSet100K
	{
		const int ARRAY_SIZE = 100000;

		int normal[100000];
		int reverse[100000];
		int random[100000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	struct DataSet1M
	{
		const int ARRAY_SIZE = 1000000;

		int normal[1000000];
		int reverse[1000000];
		int random[1000000];

		float timeToSortNormBubble = 0;
		float timeToSortNormSelection = 0;
		float timeToSortNormQuick = 0;

		float timeToSortRevBubble = 0;
		float timeToSortRevSelection = 0;
		float timeToSortRevQuick = 0;

		float timeToSortRandBubble = 0;
		float timeToSortRandSelection = 0;
		float timeToSortRandQuick = 0;
	};

	//Declare the data sets on the heap
	DataSet100* dSet100 = new DataSet100;
	DataSet1K* dSet1K = new DataSet1K;
	DataSet10K* dSet10K = new DataSet10K;
	DataSet100K* dSet100K = new DataSet100K;
	DataSet1M* dSet1M = new DataSet1M;

	clock_t clock1;

	void setupDataArrays(int normal[], int reverse[], int random[], const int ARRAY_SIZE);

	void bubbleSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE);

	void bubbleSortR(int array[], const int ARRAY_SIZE);

	void selectionSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE);

	void selectionSortR(int array[], const int ARRAY_SIZE);

	void quickSort(int normal[], int reverse[], int random[], const int ARRAY_SIZE);

	void swap(int array[], int indx1, int indx2);
};