/*
Author: Demetri Van Sickle
Date: 4/30/17
IDE: Visual Studio 2015
Program: SchedulerSim.h
Description:
		Contains the definition code for the SchedulerSim class
*/
#pragma once

#include <iostream>
#include <queue>
#include <list>
#include <fstream>
#include <string>

using namespace std;

const unsigned int PRIORITY_SIZE = 5;
const unsigned int TIME_SLICE = 20;
const unsigned int DATA_SIZE = 20;
const string FILE_NAME = "sim.data";


class SchedulerSim
{
public:
	SchedulerSim();

	~SchedulerSim();

	void setupSim();

private:
	struct task
	{
		unsigned int originalPriority;
		unsigned int currentPriority;
		unsigned int requiredTime;
		unsigned int elapsedTime;
		unsigned int processID;
		unsigned int startTime;
		unsigned int endTime;
	};

	//Set up the priority queue
	queue<task>* PriorityQueue[PRIORITY_SIZE] =
	{
		new queue<task>,
		new queue<task>,
		new queue<task>,
		new queue<task>,
		new queue<task>,
	};

	ifstream fileRead;

	int systemTime;

	////////////////////////////////////////////////////////////////

	/*
	Returns:
		True -- read file, and tasks were recorded
		False -- could NOT read file
	*/
	bool getTasks();

	/*
	Input:
		dataStream - cString or string containing the data from file
		returnTask - refrence to a task variable to return to
	*/
	void interpretData(string dataStream, task& returnTask);
};