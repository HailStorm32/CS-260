/*
Author: Demetri Van Sickle
Date: 4/22/17
IDE: Visual Studio 2015
Program: Infix-Postfix_Test.cpp
Description:
	Converts infix expressions to postfix and then evaluates them.
*/
#include "Infix2Postfix.h"

const string INFIX_EXP_1 = "5 # 2";
const string INFIX_EXP_2 = "5 * - 6 8";
const string INFIX_EXP_3 = "5*2  +   3";
const string INFIX_EXP_4 = "3 + 5 * (7-2)";
const string INFIX_EXP_5 = "3 + ( (8-5) * (4+9) )";


void main()
{
	Infix2Postfix solver;

	cout << "Author: Demetri Van Sickle\n\n" << endl;

	solver.convertAndSolve(INFIX_EXP_1);

	cout << "\n\n";

	solver.convertAndSolve(INFIX_EXP_2);

	cout << "\n\n";

	solver.convertAndSolve(INFIX_EXP_3);
	
	cout << "\n\n";

	solver.convertAndSolve(INFIX_EXP_4);

	cout << "\n\n";

	solver.convertAndSolve(INFIX_EXP_5);

	cout << "\n\n";

	//Allow console to stay open
	cin.get();
	cin.ignore();
}