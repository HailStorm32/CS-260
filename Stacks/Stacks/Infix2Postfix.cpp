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
	string infixExpNWS;
	string postfixExp;

	cout << "Processing: " << infixExpWS << endl;

	infixExpNWS = removeWhiteSpace(infixExpWS);

	if (isValid(infixExpNWS) == false)
	{
		cout << "Infix: ERROR!" << endl;
		return;
	}
	else
	{
		cout << "Infix: " << infixExpNWS << endl;
	}
	
	postfixExp = convert2Postfix(infixExpNWS);

	cout << "Postfix: " << postfixExp << endl;

	cout << "Result: " << solvePostfix(postfixExp) << endl;

}

string Infix2Postfix::removeWhiteSpace(string infixExpWS)
{
	string infixExpNWS;

	//While there is still whitespace inside
	while (infixExpWS.find(' ') != string::npos)
	{
		//Cycle through the string and remove whitespace
		for (int indx = 0; indx < infixExpWS.length(); indx++)
		{
			if (infixExpWS[indx] == ' ')
			{
				infixExpWS.erase(indx, 1);
			}
		}
	}

	infixExpNWS = infixExpWS;

	return infixExpNWS;
}

bool Infix2Postfix::isValid(string infixExpNWS)
{
	if (infixExpNWS == "")
	{
		return false;
	}

	for (int indx = 0; indx < infixExpNWS.length(); indx++)
	{
		//If the current index does NOT equal an operator or number, return false
		if ((infixExpNWS[indx] != '(' && infixExpNWS[indx] != ')' && infixExpNWS[indx] != '+' && infixExpNWS[indx] != '-'
			&& infixExpNWS[indx] != '*' && infixExpNWS[indx] != '/') && (infixExpNWS[indx] < 48 || infixExpNWS[indx] > 57))
		{
			return false;
		}

		//If the previous and current index are both operators, return false 
		if ((infixExpNWS[indx] == '+' || infixExpNWS[indx] == '-' || infixExpNWS[indx] == '*' || infixExpNWS[indx] == '/')
			&& (infixExpNWS[indx - 1] == '+' || infixExpNWS[indx - 1] == '-' || infixExpNWS[indx - 1] == '*'
				|| infixExpNWS[indx - 1] == '/'))
		{
			return false;
		}
	}
	return true;
}

string Infix2Postfix::convert2Postfix(string infixExpNWS)
{
	string postfixExp = "";

	for (int indx = 0; indx < infixExpNWS.length(); indx++)
	{
		if (infixExpNWS[indx] >= 48 && infixExpNWS[indx] <= 57)
		{
			postfixExp += infixExpNWS[indx]; //put the number into the variable
		}
		else if (infixExpNWS[indx] == '(')
		{
			operatorStack.push(infixExpNWS[indx]);
			//infixExpNWS.erase(indx, 1);
		}
		else if (infixExpNWS[indx] == '+' || infixExpNWS[indx] == '-' || infixExpNWS[indx] == '*' || infixExpNWS[indx] == '/')
		{
			//NOTE: greater operator stays on top of stack

			if (operatorStack.empty() == true)
			{
				operatorStack.push(infixExpNWS[indx]);
			}
			else
			{
				while (operatorStack.empty() != true && isGreaterThan(operatorStack.top(), infixExpNWS[indx]))
				{
					
					postfixExp += operatorStack.top();
					operatorStack.pop();
				}

				operatorStack.push(infixExpNWS[indx]);
			}
		}
		else if (infixExpNWS[indx] == ')')
		{
			while (operatorStack.top() != '(')
			{
				postfixExp += operatorStack.top();
				operatorStack.pop();
			}

			//Pop the '('
			operatorStack.pop();
		}

	}
	
	//top and pop the remaining operators off the stack
	while (operatorStack.empty() != true)
	{
		if (operatorStack.top() != '(' && operatorStack.top() != ')')
		{
			postfixExp += operatorStack.top();
			operatorStack.pop();
		}
		else
		{
			operatorStack.pop();
		}
	}

	return postfixExp;
}

float Infix2Postfix::solvePostfix(string postfixExp)
{
	float num1 = 0;
	float num2 = 0;
	float result = 0;
	char holder;
	
	for (int indx = 0; indx < postfixExp.length(); indx++)
	{
		//Put the operands into the stack
		if (postfixExp[indx] >= 48 && postfixExp[indx] <= 57)
		{
			holder = postfixExp[indx];
			operandStack.push(atoi(&holder));
		}
		
		//Figure out what operation to preform
		if (postfixExp[indx] == '+' || postfixExp[indx] == '-' || postfixExp[indx] == '*' || postfixExp[indx] == '/')
		{
			switch (postfixExp[indx])
			{
			case '+':
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				result = num1 + num2;
				operandStack.push(result);
				break;
			case '-':
				num2 = operandStack.top();
				operandStack.pop();

				num1 = operandStack.top();
				operandStack.pop();

				result = num1 - num2;
				operandStack.push(result);
				break;
			case '*':
				num1 = operandStack.top();
				operandStack.pop();

				num2 = operandStack.top();
				operandStack.pop();

				result = num1 * num2;
				operandStack.push(result);
				break;
			case '/':
				num2 = operandStack.top();
				operandStack.pop();

				num1 = operandStack.top();
				operandStack.pop();

				result = num1 / num2;
				operandStack.push(result);
				break;
			}
		}
		//We have reached the end of the equation
		/*if (operandStack.size() == 1)
		{
			break;
		}*/
	}
	return result;
}

bool Infix2Postfix::isGreaterThan(const char & leftSide, const char & rightSide)
{
	unsigned int leftSideValue = 0;
	unsigned int rightSideValue = 0;

	//Check to make sure the right arguments were given
	if ((leftSide != '+' && leftSide != '-' && leftSide != '*'
		&& leftSide != '/') || (rightSide != '+' && rightSide != '-'
			&& rightSide != '*' && rightSide != '/'))
	{
		return false;
	}

	//Find the value of the operators
	for (int indx = 0; indx < 4; indx++)
	{
		if (leftSide == operatorPriority[indx])
		{
			leftSideValue = indx;
		}

		if (rightSide == operatorPriority[indx])
		{
			rightSideValue = indx;
		}

		//If both operators have a value assigned, break from loop
		if (rightSideValue != 0 && leftSideValue != 0)
		{
			break;
		}
	}

	//Evaluate 
	if (leftSideValue > rightSideValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}
