/******************************************************
Title:			main.cpp
Author:			Michael Garod
Date Created:	3/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #2
Description:	Runs client functions to ensure that the assignment's
				requirements have been met
******************************************************/

#include <iostream>
#include "LinkedPolynomial.h"
using namespace std;

// Function Prototypes
template<class ItemType>
LinkedPolynomial<double> CreatePolynomialFromInput();

template<class ItemType>
void TestPolynomial();

template<class ItemType>
void TestAddition();


// Main
int main()
{
	cout << "Running first test function: CreatePolynomialFromInput<double>()\n\n";
	LinkedPolynomial<double> some_polynomial =
							CreatePolynomialFromInput<double>();
	cout << "You created: "; some_polynomial.DisplayPolynomial();

	cout << "\nRunning second test function: TestPolynomial<double>()\n\n";
	TestPolynomial<double>();

	cout << "\nRunning third and final test function: TestAddition<double>()\n\n";
	TestAddition<double>();

	return 0;
}

// Function Definitions

// Description: Creates a new Polynomial of any size, based on user input
template<class ItemType>
LinkedPolynomial<double> CreatePolynomialFromInput()
{
	/*****
	PAGE 2-3 PART A

	ASK USER FOR COEFFICIENTS AND EXPONENTS

	ERROR CHECK EVERYTHING
	USE EXCEPTIONS
	*****/
	LinkedPolynomial<double> fn_poly;

	char c;

	cout << "Press Y or y to create a non-empty polynomial\n";
	cout << "Otherwise, an empty polynomial will be created\n";
	cin >> c;

	while ( c == 'y' || c == 'Y')
	{
		double exponent, coefficient;

		cout << "\nInput an exponent (double): ";
		while (!(cin >> exponent))
		{	// If bad input, reset the input stream
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Please input a decimal number.\n";
		}

		cout << "\nInput an coefficient (double): ";
		while (!(cin >> coefficient))
		{	// If bad input, reset the input stream
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Please input a decimal number.\n";
		}

		fn_poly.Add(coefficient, exponent);

		cout << "\nInput another exponent and coefficient?\n";
		cout << "Press Y or y to continue: ";
		cin >> c;
	}

	// Reset the Input Stream
	cin.clear();
	cin.ignore(1000, '\n');

	return fn_poly;
}


// Description: Validates that the following methods work
//		DisplayPolynomial()
//		Degree()
//		Coefficient()
//		ChangeCoefficient()
template<class ItemType>
void TestPolynomial()
{
	/*****
	Action List:

	Call CreatePolynomialFromInput()
	Call Method.DisplayPolynomial()
	cout << Method.Degree()
	cin >> exponent
	cout << Method.Coefficient(exponent)
	cin >> new_coefficient
	cout << Method.ChangeCoefficient(new_coefficient, exponent)
	Call Method.DisplayPolynomial()
	*****/

	LinkedPolynomial<double> poly1 = CreatePolynomialFromInput<double>();
	poly1.DisplayPolynomial();

	cout << "Degree(): " << poly1.Degree() << endl;
	
	double search_exp, search_coef;

	cout << "Enter an exponent whose coefficient you wish to find: ";	
	while (!(cin >> search_exp))
	{	// If bad input, reset the input stream
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please input a decimal number.\n";
	}

	// Display the coefficient of the user input exponent
	cout << "\nCoefficient(" << search_exp << "): "
		 << poly1.Coefficient(search_exp) << endl;

	cout << "Enter a new coefficient for that exponent: ";
	while (!(cin >> search_coef))
	{	// If bad input, reset the input stream
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please input a decimal number.\n";
	}

	// The line will display 0 or 1 depending on if the change was successful
	cout << "Coefficient changed: "
		 << poly1.ChangeCoefficient(search_coef, search_exp) << endl;

	poly1.DisplayPolynomial();
}

// Description: Validates that method AddPolynomial() Works
template<class ItemType>
void TestAddition()
{
	cout << "Make the first polynomial: \n";
	LinkedPolynomial<double> polynomial1 = CreatePolynomialFromInput<double>();

	cout << "Make the second polynomial: \n";
	LinkedPolynomial<double> polynomial2 = CreatePolynomialFromInput<double>();

	cout << "Your first Polynomial is: "; polynomial1.DisplayPolynomial();
	cout << "Your second Polynomial is: "; polynomial2.DisplayPolynomial();

	// Addition is called here
	polynomial1.AddPolynomial(polynomial2);

	// Final result
	cout << "Polynomial1 = Polynomial1 + Polynomial 2: ";
	polynomial1.DisplayPolynomial();
}
