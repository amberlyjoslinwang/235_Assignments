/******************************************************
Title:			Test.cpp
Author:			Michael Garod
Date Created:	4/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #3
Description:	Uses the InfixToPostfixCalculator class to calculate
				various mathematical expressions by converting the
				standard infix notation to postfix notation, then
				computing the result.
******************************************************/
#include "InfixToPostfixCalculator.h"
#include <fstream>
using namespace std;

int main()
{
	InfixToPostfixCalculator myCalc;
	ifstream input("infixFile");
	ofstream output("resultFile");

	string infixExpression;
	
	while (getline(input, infixExpression))
	{
		// Skip empty lines in the infixFile
		if (infixExpression.length() == 0)
		{
			continue;
		}

		// Attempt to generate postfix and calculate
		string postfixExpression;
		double answer;

		try
		{
			postfixExpression = myCalc.ConvertInfixToPostfix(infixExpression);
			output << postfixExpression<< endl;

			answer = myCalc.CalculatePostfix(postfixExpression);
			output << " = " << answer << endl << endl;
		}
		catch (PreconditionViolatedException& ex)
		{
			output << ex.what() << endl << endl;
			continue;
		}

	}
	
	input.close();
	output.close();
	
	return 0;
}
