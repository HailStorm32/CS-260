/*
Author: Demetri Van Sickle
Date: 4/30/17
IDE: Visual Studio 2015
Program: SchedulerSim.cpp
Description:
		Contains the implementation for the SchedulerSim class
*/

#include "SchedulerSim.h"

SchedulerSim::SchedulerSim()
{

}

SchedulerSim::~SchedulerSim()
{
	delete[] PriorityQueue;
}

bool SchedulerSim::getTasks()
{
	fileRead.open(FILE_NAME);

	task task1;
	char lineStream[DATA_SIZE];

	if (fileRead.is_open() == false)
	{
		cerr << "Cant open file: " << FILE_NAME << " !!\n";
		return false;
	}

	while (!fileRead.eof())
	{
		fileRead.getline(lineStream, DATA_SIZE);


	}
}

bool SchedulerSim::interpretData(string dataStream, task& returnTask)
{
	string dataHolder;
	
	//Run through the string and take out the data
	for (int indx = 0; indx < dataStream.length(); indx++)
	{
		//Take out the priority level
		if(dataStream[indx] >= 48 && dataStream[indx] <= 57)
		{
			returnTask.originalPriority += static_cast<int>(dataStream[indx]);
		}

		returnTask.currentPriority = returnTask.originalPriority;

		//Run through the whitespace until the next chunk of data
		while (dataStream[indx] == ' '){}

		while (dataStream[indx] >= 48 && dataStream[indx] <= 57)
		{
			returnTask.requiredTime += dataStream[indx];
		}

	}
}
