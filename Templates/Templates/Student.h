/*
Program: Student.h
Author: Demetri Van Sickle
Date: 4/12/17
IDE: Visual Studio 2015
Description:
	Contains the code for the student class
*/
#pragma once
#include <iostream>

using namespace std;

class Student {
public:
	//constructor
	Student(const string name = "anonymous", char letterGrade = 'W')
	{
		this->name = name;
		this->letterGrade = letterGrade;
	}

	//operator overloads
	friend bool operator== (const Student& stu1, const Student& stu2)
	{
		if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
			return true;
		else
			return false;
	}

	friend ostream& operator<< (ostream& stream, const Student& student)
	{
		stream << student.name.c_str();//had to convert to cString otherwise I would get a C2679 error

		stream << " (" << student.letterGrade << ") ";
		return stream;
	}

private:

	string name;
	char letterGrade;
};
