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
	for (int indx = 0; indx < PRIORITY_SIZE; indx++)
	{
		delete PriorityQueue[indx];
	}
}

void SchedulerSim::setupSim()
{
	getTasks();

	systemTime = 0;
}

bool SchedulerSim::getTasks()
{
	fileRead.open(FILE_NAME);

	task tempTask;
	char lineStream[DATA_SIZE];

	if (fileRead.is_open() == false)
	{
		cerr << "Cant open file: " << FILE_NAME << " !!\n";
		return false;
	}

	while (!fileRead.eof())
	{
		fileRead.getline(lineStream, DATA_SIZE);

		interpretData(lineStream, tempTask);

		PriorityQueue[tempTask.currentPriority]->push(tempTask);
	}
	return true;
}

void SchedulerSim::interpretData(string dataStream, task& returnTask)
{
	string dataHolder;
	unsigned int indx = 0;
	string holder;

	static unsigned int processID = 1;

	//Run through the string and take out the data

	//Run through the whitespace until the next chunk of data
	while (indx < dataStream.length() && dataStream[indx] == ' ')
	{
		indx++;
	}

	//Take out the priority level
	while (indx < dataStream.length() && (dataStream[indx] >= 48 && dataStream[indx] <= 57))
	{
		holder += dataStream[indx];
		indx++;
	}

	returnTask.originalPriority = atoi(holder.c_str());
	returnTask.currentPriority = returnTask.originalPriority;

	//Run through the whitespace until the next chunk of data
	while (indx < dataStream.length() && dataStream[indx] == ' ')
	{
		indx++;
	}


	holder = "";

	//Take the required time
	while (indx < dataStream.length() && (dataStream[indx] >= 48 && dataStream[indx] <= 57))
	{
		holder += dataStream[indx];
		indx++;
	}

	returnTask.requiredTime = atoi(holder.c_str());

	returnTask.processID = processID;

	returnTask.elapsedTime = 0;
	returnTask.startTime = 0;
	returnTask.endTime = 0;

	processID++;
}
