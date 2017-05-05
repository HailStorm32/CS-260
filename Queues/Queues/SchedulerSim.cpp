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
	cout << "Setting up simulation...\n\n";

	getTasks();

	systemTime = 0;


	//////////////////////////////////////
	/*task debugTask;

	debugTask.currentPriority = 2;
	debugTask.elapsedTime = 1000;
	debugTask.endTime = 300;
	debugTask.originalPriority = 0;
	debugTask.processID = 1;
	debugTask.requiredTime = 45;
	debugTask.startTime = 200;*/
	///////////////////////////////////////

	//Setup the table;
	cout << setw(8) << setfill(' ') << "        Initial" << setw(8) << setfill(' ') << "Time"
		<< setw(8) << setfill(' ') << "Time" << setw(8) << setfill(' ') << "Time"
		<< setw(8) << setfill(' ') << "     Elapsed" << setw(8) << setfill(' ') << "   Final\n";

	cout << "PID" << setw(8) << setfill(' ') << "     Priority"
		<< setw(8) << setfill(' ') << "Needed" << setw(8) << setfill(' ') << "Started"
		<< setw(8) << setfill(' ') << "Ended" << setw(8) << setfill(' ') << "Time"
		<< setw(8) << setfill(' ') << "     Priority\n";

	//printTask(debugTask);
}

void SchedulerSim::startSim()
{
	int sectionToServe = tasksExist();
	task tempTask;

	while (tasksExist() != -1)
	{
		tempTask = PriorityQueue[sectionToServe]->front();
		PriorityQueue[sectionToServe]->pop();

		//Does task need to be ran again?
		if (runTask(tempTask))
		{
			//Only decrease priority if it isnt already to the lowest
			if (tempTask.currentPriority != 4)
			{
				tempTask.currentPriority++;
			}

			//Re-insert into queue
			PriorityQueue[tempTask.currentPriority]->push(tempTask);
		}
		else
		{
			printTask(tempTask);
		}
	}
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

int SchedulerSim::tasksExist()
{
	for (int indx = 0; indx < PRIORITY_SIZE; indx++)
	{
		if (PriorityQueue[indx]->empty() == false)
		{
			return indx;
		}
	}

	return -1;
}

bool SchedulerSim::runTask(task& taskToRun)
{
	int passedTime = 0;

	//Only give a start time if task hasn't been run already
	if (taskToRun.startTime == 0)
	{
		taskToRun.startTime = systemTime;
	}

	//"run" the task until the time has passed
	while (taskToRun.requiredTime <= passedTime && passedTime <= TIME_SLICE)
	{
		passedTime++;
		systemTime++;
	}

	taskToRun.endTime = systemTime;

	//If task still needs to be run
	if (taskToRun.requiredTime > TIME_SLICE)
	{
		//Calculate how much time the task needs to complete the rest of the task
		taskToRun.requiredTime = taskToRun.requiredTime - TIME_SLICE;

		return true;
	}
	//If task is done
	else
	{
		//Calculate the total time it took to complete it
		taskToRun.elapsedTime = taskToRun.endTime - taskToRun.startTime;

		return false;
	}
}

void SchedulerSim::printTask(const task & taskToPrint)
{
	const int width = 10;
	
	cout << taskToPrint.processID << setw(width) << setfill(' ') << "     " << taskToPrint.originalPriority
		<< setw(width) << setfill(' ') << taskToPrint.requiredTime << setw(width) << setfill(' ') << taskToPrint.startTime
		<< setw(width) << setfill(' ') << taskToPrint.endTime << setw(width) << setfill(' ') << taskToPrint.elapsedTime
		<< setw(width) << setfill(' ') << "     " << taskToPrint.currentPriority << endl;
}
