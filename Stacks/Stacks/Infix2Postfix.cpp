/*
Author: Demetri Van Sickle
Date: 4/22/17
IDE: Visual Studio 2015
Program: Infix2Postfix.cpp
Description:
	Contains the implementation for the Infix2Postfix class
*/
#include "Infix2Postfix.h"

Infix2Postfix::Infix2Postfix()
{
}

Infix2Postfix::~Infix2Postfix()
{
}

void Infix2Postfix::convertAndSolve(string infixExpWS)
{
	cout << "Processing: " << infixExpWS << endl;

	if (isValid(infixExpWS) == false)
	{
		cout << "FALSE" << endl;
	}
	else
	{
		cout << "true";
	}
}

string Infix2Postfix::removeWhiteSpace(string infixExpWS)
{
	return string();
}

bool Infix2Postfix::isValid(string infixExpNWS)
{
	for (int indx = 0; indx < infixExpNWS.length(); indx++)
	{
		if((infixExpNWS[indx] != '(' && infixExpNWS[indx] != ')' && infixExpNWS[indx] != '+' && infixExpNWS[indx] != '-' 
			&& infixExpNWS[indx] != '*' && infixExpNWS[indx] != '/') && (infixExpNWS[indx] < 48 || infixExpNWS[indx] > 57))
		{
			return false;
		}
	}
	return true;
}

string Infix2Postfix::convert2Postfix(string infixExpNWS)
{
	return string();
}

float Infix2Postfix::solvePostfix(string postfixExp)
{
	return 0.0f;
}
