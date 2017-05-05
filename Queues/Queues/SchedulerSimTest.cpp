/*
Author: Demetri Van Sickle
Date: 4/30/17
IDE: Visual Studio 2015
Program: SchedulerSimTest.cpp
Description:
		Tests the SchedulerSim class
*/

#include "SchedulerSim.h"

void main()
{
	cout << "Author: Demetri Van Sickle\n\n" << endl;
	
	SchedulerSim newSim;

	newSim.setupSim();
	
	newSim.startSim();
}