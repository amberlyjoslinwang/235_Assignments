/******************************************************
Title:			InfixToPostfixCalculator.cpp
Author:			Michael Garod
Date Created:	4/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #3
Description:	Implementation file for InfixToPostfixCalculator class.
******************************************************/

#include "InfixToPostfixCalculator.h"
#include <sstream>


// Default Constrcutor
InfixToPostfixCalculator::InfixToPostfixCalculator()
{
	// Has no members to initialize
}


string InfixToPostfixCalculator::ConvertInfixToPostfix
	(const string& input_infix) throw(PreconditionViolatedException)
{
	LinkedStack<char> op_stack;
	string result;
	
	// Most exceptions can only come from within checkExceptionsOnInfix
	checkExceptionsOnInfix(input_infix);
	
	// Begin parsing Infix to Postfix
	for (unsigned int i = 0; i < input_infix.length(); i++)
	{
		// Converting infix to postfix
		switch (input_infix[i])
		{
			// Lowest Order operators (preserves left to right)
		case '+':
		case '-':	// Popping all operators until '('
			while (!op_stack.IsEmpty() && (op_stack.Peek() != '('))
			{
				result = appendToResult(result, op_stack.Peek() );
				result = appendToResult(result, ',');
				op_stack.Pop();
			}

			op_stack.Push(input_infix[i]); // Saving the last operator
			break;

			// Highest Order operators (preserves left to right)
		case '*':
		case '/':	// Popping only greater or equal prescedence or until '('
			while (!op_stack.IsEmpty() && (op_stack.Peek() != '(')
				&& (op_stack.Peek() != '+') && (op_stack.Peek() != '-') )
			{
				result = appendToResult(result, op_stack.Peek());
				result = appendToResult(result, ',');
				op_stack.Pop();
			}

			op_stack.Push(input_infix[i]);	// Saving the last operator

			break;

			// Simply push a '(', order of operations handled by others
		case '(':
			op_stack.Push(input_infix[i]);
			break;

			// Almost same as Lowest order operator but 
		case ')':
			while (!op_stack.IsEmpty() && (op_stack.Peek() != '(') )
			{
				result = appendToResult(result, op_stack.Peek());
				result = appendToResult(result, ',');
				op_stack.Pop();
			}

			if (!op_stack.IsEmpty() && op_stack.Peek() == '(')
			{
				op_stack.Pop();
			}
			break;
	
			// When encountering whitespace, do nothing (discard)
		case ' ':
		case '\t':
		case '\v':
		case '\f':
		case '\r':
			break;
		
		case '.':
			result = appendToResult(result, '.');
			i++;
			// Find the first thing after the decimal

			// Begin by skipping all spaces until a non-space
			while (isspace(input_infix[i]) && i < input_infix.length())
			{
				i++;
				// Exception case: if there is an operator or parenthesis
				//	after inspecting a decimal point
				if (isMathOp(input_infix[i]) || isParenthesis(input_infix[i])
					|| input_infix[i] == '.')
				{
					throw PreconditionViolatedException
						("Infix expression has a misplaced decimal point");
				}
			}

			// Take all the 
			while ( isdigit(input_infix[i]) && i < input_infix.length())
			{
				result = appendToResult(result, input_infix[i]);
				i++;
			}
			i--;
			
			if (isMathOp(input_infix[i]) || isParenthesis(input_infix[i])
				|| input_infix[i] == '.')
			{
				throw PreconditionViolatedException
					("Infix expression has a misplaced decimal point");
			}

			result = appendToResult(result, ',');
			break;

			// Case for handling non-operators (alpha-numeric characters)
		default:
			// Once an alpha-numeral is found, get any additional
			// alpha-numerals such as multi-digit nubers
			while (isdigit(input_infix[i]) && i < input_infix.length() )
			{	
				result = appendToResult(result, input_infix[i]);
				i++;
			}

			// Case for numbers with decimal points
			if (input_infix[i] == '.')
			{
				result = appendToResult(result, '.');
				i++;
				while (isdigit(input_infix[i]) && i < input_infix.length())
				{
					result = appendToResult(result, input_infix[i]);
					i++;
				}
			}

			// The final i++ above brings us to an operator
			// So we must backstep by 1 because the for loop will i++
			// again, therefore skipping that operator
			i--;

			result = appendToResult(result, ',');
			break;
		}
	}

	// Clearing the stack of whatever remains
	while (!op_stack.IsEmpty())
	{
		result = appendToResult(result, op_stack.Peek());
		result = appendToResult(result, ',');
		op_stack.Pop();
	}

	// Because every addition to string result also appends ','
	// This is removing the final ',' 
	result.resize(result.length() - 1);


	/*
	"An infix expression is valid
	<---IF AND ONLY IF--->
	the equivalent postfix expression has a solution"

	Therefore, I attempt to find the solution here.
	If it as a solution, great, proceed.
	If it doesn't, then the appropriate exception will be thrown here.
	*/
	//CalculatePostfix(result);

	return result;
}

double InfixToPostfixCalculator::CalculatePostfix(
	const string& input_postfix) throw(PreconditionViolatedException)
{
	// Exception case: Postfix Expression has illegal characters
	bool hasOnlyLegalChars = containsOnlyLegalPostFixCharacters(input_postfix);
	if (false == hasOnlyLegalChars)
	{
		throw PreconditionViolatedException
			("Postfix expression contains illegal characters");
	}

	// Data required for the calculations
	LinkedStack<double> num_stack;
	stringstream ss(input_postfix);
	string substr;

	// Begin parsing postfix expression
	while (getline(ss, substr, ',') )
	{	
		// This getline() retrieves everything until the next ',' or '\n'
		// (which is a single char) because ConvertInfixToPostFix()
		// strictly formats to ensure this.
		
		if (isMathOp(substr[0]))
		{
			// Exception case: More operators than numbers
			calculateOperation(substr[0], num_stack);
		}
		else
		{
			double number = stod(substr);
			num_stack.Push(number);
		}

	}
	
	double result = num_stack.Peek();
	num_stack.Pop();

	// Exception case: More numbers than operators
	//	This is determined if there are numbers remaining in the stack
	//	after all operations are processed.
	if (!num_stack.IsEmpty())
	{
		throw PreconditionViolatedException
			("Postfix Expression has more numbers than operators");
	}

	return result;
}




/**** General Private Functions ****/

// appendToResult
string InfixToPostfixCalculator::appendToResult(string input_string, char append)
{
	return input_string + append;
}


// isMathOp - Parentheses are not Math Operators for this function
bool InfixToPostfixCalculator::isMathOp(const char& input) const
{
	if (input == '+' || input == '-' || input == '*' || input == '/')
	{
		return true;
	}
	return false;
}


// isParenthesis
bool InfixToPostfixCalculator::isParenthesis(const char& input) const
{
	if (input == '(' || input == ')')
	{
		return true;
	}
	return false;
}


/**** Private Functions for Infix Expressions ****/

// hasBalancedParentheses
// CAN NEVER RETURN FALSE. If parentheses are unbalanced, then an exception
//	is thrown indicating which way the parentheses are unbalanced.
//	Otherwise, the method returns TRUE.
bool InfixToPostfixCalculator::hasBalancedParentheses(
	const string& input_infix) const
{
	LinkedStack<char> bal_stack;
	bool balanced = true;

	for (unsigned int i = 0; i < input_infix.length() && balanced; i++)
	{
		if (input_infix[i] == '(')
		{
			bal_stack.Push(input_infix[i]);
		}
		else if (input_infix[i] == ')')
		{
			balanced = bal_stack.Pop();
		}
	}

	
	if (!bal_stack.IsEmpty())
	{
		throw PreconditionViolatedException
			("Infix Expression has too many open parenthesis");
	}
	else if (false == balanced)
	{
		throw PreconditionViolatedException
			("Infix Expression has too many close parenthesis");
	}
	
	// These must be true if the method has reached this point
	return (bal_stack.IsEmpty() && balanced);
}


// hasConsecutiveMathOps (Pretty much the inverse of hasConsecutiveOperands)
bool InfixToPostfixCalculator::hasConsecutiveMathOps(
	const string& input_infix) const
{
	bool hasConsec = false;

	for (unsigned int i = 1; i < input_infix.length(); i++)
	{
		// Exception case: Infix has two consecutive operators
		if (isMathOp(input_infix[i]) )
		{
			int j = i - 1;
			hasConsec = false;	// innocent until guilty

			while (j > 0 && hasConsec == false)
			{
				if (isdigit(input_infix[j]) )
				{
					break;	// stop when we reach first number
				}
				else if (isMathOp(input_infix[j]) )
				{
					hasConsec = true;
					return hasConsec;
				}
				else		// case for space or parentheses is inconclusive
				{
					j--;	// go to previous char
				}
			}
		}
	}

	return hasConsec;	// false if the infixExpression is legal
}


// hasConsecutiveOperands (Pretty much the inverse of hasConsecutiveMathOps)
bool InfixToPostfixCalculator::hasConsecutiveOperands(
	const string& input_infix) const
{
	bool hasConsec = false;
	bool seenDecimal = false;

	for (unsigned int i = 1; i < input_infix.length(); i++)
	{
		// Reset conditions every loop
		seenDecimal = false;
		hasConsec = false;

		// Exception case: Infix has two consecutive operators
		if (isdigit(input_infix[i]))
		{
			int j = i - 1;
			
			// Skip the numbers until you see a a first decimal
			while (j >= 0 && (isdigit(input_infix[j]) || input_infix[j] == '.')
					&& seenDecimal==false)
			{
				j--;
				if (j >= 0 && input_infix[j] == '.')
				{
					seenDecimal = true;
					j--;
				}
			}

			// Skip all numbers after seeing exactly 1 decimal
			while (j >= 0 && isdigit(input_infix[j]))
			{	
				j--;
			} 
			
			// Check what comes before the number just observed
			while (j >= 0 && hasConsec == false)
			{
				if (isMathOp(input_infix[j]) )
				{
					break;	// stop when we reach first operator
				}
				else if (isdigit(input_infix[j]) )
				{
					hasConsec = true;
					return hasConsec;
				}
				else		// case for space or parentheses is inconclusive
				{
					j--;	// go to previous char
				}
			}
		}
	}

	return hasConsec;	// false if the infixExpression is legal
}


// is First Item an Operand
bool InfixToPostfixCalculator::isFirstItemAnOperand(
	const string& input_infix) const
{
	unsigned int i = 0;

	// Move to the first thing that isn't a space or a parentheses
	while (i < input_infix.length() && (isspace(input_infix[i]) ||
		input_infix[i] == '(' || input_infix[i] == ')') )
	{
		i++;
	}

	// If that first thing is an operator return false, otherwise true
	if (isMathOp(input_infix[i]))
	{	
		return false;
	}
	else
	{
		return true;
	}
}

// does it contain non-digit, non-mathop characters?
bool InfixToPostfixCalculator::containsOnlyLegalCharacters(const string& input_infix) const
{
	for (unsigned int i = 0; i < input_infix.length(); i++)
	{
		char ch = input_infix[i];

		// If any character in input_infix is illegal, return false
		if (!isMathOp(ch) && !isdigit(ch) &&
			!isblank(ch) && !isParenthesis(ch) && ch != '.' )
		{
			return false;
		}
	}

	return true;
}

// does Infix end with an operator
bool InfixToPostfixCalculator::isLastItemAnOperator(const string& input_infix) const
{
	int i = static_cast<int>(input_infix.length() - 1);
	
	while (i >= 0)
	{
		if (isMathOp(input_infix[i]) )
		{
			return true;
		}
		else if (isdigit(input_infix[i]) )
		{
			return false;
		}
		else
		{
			i--;
		}
	}
	return false;
}

// Runs all exception private methods
void InfixToPostfixCalculator::checkExceptionsOnInfix(
	const string& input_infix) const
{
	// Exception case: contains unexpected characters. We only 
	//	expect digits, whitespace, and elementary math operation symbols 
	if (false == containsOnlyLegalCharacters(input_infix))
	{
		throw PreconditionViolatedException
			("Infix Expression has an illegal character");
	}

	// Exception case: First item in Infix Expression is an Operator
	if (false == isFirstItemAnOperand(input_infix))
	{
		throw PreconditionViolatedException
			("The first item in the Infix Expression is an Operator");
	}

	if (true == isLastItemAnOperator(input_infix))
	{
		throw PreconditionViolatedException
			("The last item in Infix Expression is an Operator");
	}

	// Exception case: Unbalanced Parentheses
	// hasBalancedParentheses() will throw the exception and pass it up
	hasBalancedParentheses(input_infix);


	// Exception case: Consecutive Math Operators within Infix Expression
	if (true == hasConsecutiveMathOps(input_infix))
	{
		throw PreconditionViolatedException
			("Infix Expression has consecutive operators");
	}

	// Exception case: Consecutive Operands within Infix Expression
	if (true == hasConsecutiveOperands(input_infix))
	{
		throw PreconditionViolatedException
			("Infix Expression has consecutive operands");
	}

	// All exceptions have been checked, there is nothing wrong
	// with the input infix expression
	return;
}



/**** Private Functions for Postfix Expressions ****/

bool InfixToPostfixCalculator::isValidPostSymbol(const char& input) const
{
	char ch = input;

	if (isMathOp(ch) || isdigit(ch) || isblank(ch))
	{
		return true;
	}
	return false;
}


void InfixToPostfixCalculator::calculateOperation
	(const char& symbol, LinkedStack<double>& num_stack) const
{
	// Exception Case: Operator called with zero previous numbers
	//  on the postfix stack (Prevents peeking an empty stack)
	if (num_stack.IsEmpty())
	{
		throw PreconditionViolatedException
			("Postfix operator called with no available operands");
	}
	double num2 = num_stack.Peek();
	num_stack.Pop();

	// Exception Case: Operator called with only 1 previous number
	//  on the postfix stack (Prevents peeking an empty stack)
	if (num_stack.IsEmpty())
	{
		throw PreconditionViolatedException
			("Postfix operator with only 1 available operand");
	}
	double num1 = num_stack.Peek();
	num_stack.Pop();

	switch (symbol)
	{

	case '+':
		num_stack.Push(num1 + num2);
		break;

	case '-':
		num_stack.Push(num1 - num2);
		break;

	case '*':
		num_stack.Push(num1 * num2);
		break;

	case '/':
		num_stack.Push(num1 / num2);
		break;

	default:
		// This exception is basically impossible since the method
		// containsOnlyLegalPostFixCharacters() has run previously,
		// but will keep this here for safety
		throw PreconditionViolatedException
			("Postfix Expression contains an unexpected character");
	}

}


bool InfixToPostfixCalculator::containsOnlyLegalPostFixCharacters
	(const string& input_postfix) const
{
	for (unsigned int i = 0; i < input_postfix.length(); i++)
	{
		char ch = input_postfix[i];

		// If any character in input_infix is illegal, return false
		if (!isMathOp(ch) && !isdigit(ch) &&
			!isblank(ch) && ch != ',' && ch != '.')
		{
			return false;
		}
	}

	return true;
}
