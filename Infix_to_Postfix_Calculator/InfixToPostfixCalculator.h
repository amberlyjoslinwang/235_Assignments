/******************************************************
Title:			InfixToPostfixCalculator.h
Author:			Michael Garod
Date Created:	4/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #3
Description:	Header file for the class InfixToPostfixCalculator
******************************************************/

#ifndef INFIXTOPOSTFIXCALCULATOR_H
#define INFIXTOPOSTFIXCALCULATOR_H

#include "LinkedStack.h"
#include <iostream>

using namespace std;

class InfixToPostfixCalculator
{
	public:
		InfixToPostfixCalculator();
		string ConvertInfixToPostfix(const string& input_infix)
			throw(PreconditionViolatedException);
		double CalculatePostfix(const string& input_postfix)
			throw(PreconditionViolatedException);

	private:
		string appendToResult(string input_string, char append);
		bool isMathOp(const char& input) const;
		bool isParenthesis(const char& input) const;

		// These are to check infix expressions only
		bool hasBalancedParentheses(const string& input_infix) const;
		bool hasConsecutiveMathOps(const string& input_infix) const;
		bool hasConsecutiveOperands(const string& input_infix) const;
		bool isFirstItemAnOperand(const string& input_infix) const;
		bool containsOnlyLegalCharacters(const string& input_infix) const;
		bool isLastItemAnOperator(const string& input_infix) const;
		void checkExceptionsOnInfix(const string& input_infix) const;

		// These are to check postfix expressions only
		bool isValidPostSymbol(const char& input) const;
		void calculateOperation(const char& symbol,
			LinkedStack<double>& num_stack) const;
		bool containsOnlyLegalPostFixCharacters
			(const string& input_infix) const;
		
};

#endif
