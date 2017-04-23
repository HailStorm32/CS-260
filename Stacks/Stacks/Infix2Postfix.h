/*
Author: Demetri Van Sickle
Date: 4/22/17
IDE: Visual Studio 2015
Program: Infix2Postfix.cpp
Description:
	Contains the definition for the Infix2Postfix class
*/
#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Infix2Postfix
{
public:

	Infix2Postfix();

	~Infix2Postfix();

	/*
	Input: 
		string - no empty string
	*/
	void convertAndSolve(string infixExpWS);

private:
	stack<char> operatorStack;
	string printBuffer;

	/*
	Input:
		string - no empty strings, must ONLY contain valid operators and numbers
	Output:
		string - expression without white space 
	*/
	string removeWhiteSpace(string infixExpWS);

	/*
	Input:
		string - no empty strings
	Output:
		True - string ONLY contains valid operators and numbers
		False - string contains invalid operators and numbers
	*/
	bool isValid(string infixExpWS);

	/*
	Input:
		string - no empty strings
	Output:
		string - postfix expression
	*/
	string convert2Postfix(string infixExpNWS);

	/*
	Input:
		string - no emtpy string, and MUST be formated in postfix
	Output:
		result from solving the expression
	*/
	float solvePostfix(string postfixExp);

};