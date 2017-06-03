#pragma once
/*
Author: Demetri Van Sickle
Date: 6/2/17
IDE: Visual Studio 2015
Program: Sorter.h
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Sorter
{
public:
	Sorter();

	~Sorter();

private:
	struct DataSet100
	{
		const int ARRAY_SIZE = 100;

		int normal[100]; // = new int[ARRAY_SIZE];
		int reverse[100]; // = new int[ARRAY_SIZE];
		int random[100]; // = new int[ARRAY_SIZE];
	};

	struct DataSet1K
	{
		const int ARRAY_SIZE = 1000;

		int* normal = new int[ARRAY_SIZE];
		int* reverse = new int[ARRAY_SIZE];
		int* random = new int[ARRAY_SIZE];
	};

	struct DataSet10K
	{
		const int ARRAY_SIZE = 10000;

		int* normal = new int[ARRAY_SIZE];
		int* reverse = new int[ARRAY_SIZE];
		int* random = new int[ARRAY_SIZE];
	};

	struct DataSet100K
	{
		const int ARRAY_SIZE = 100000;

		int* normal = new int[ARRAY_SIZE];
		int* reverse = new int[ARRAY_SIZE];
		int* random = new int[ARRAY_SIZE];
	};

	struct DataSet1M
	{
		const int ARRAY_SIZE = 1000000;

		int* normal = new int[ARRAY_SIZE];
		int* reverse = new int[ARRAY_SIZE];
		int* random = new int[ARRAY_SIZE];
	};



	void setupDataArrays(int normal[], int reverse[], int  random[], const int ARRAY_SIZE);
};