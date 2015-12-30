/***************************************************************
Title:			README.txt
Author:			Michael Garod
Date Created:	3/14/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #2
Description:	Brief description containing which parts of the assignment were
				completed, bugs encountered, instructions on how to run
				the program, and input/output files necessary or created.
Contents:		This .zip file should contain this README.txt, makefile,
				LinkedPolynomial.cpp, LinkedPolynomial.h, Node.cpp, node..h,
				and main.cpp
Note:			This project was built with base code provided by 
				Pearson Education, Inc. which can be found on their website.
***************************************************************/

I. Parts Completed
	- All parts of assignment were completed
	- Where applicable, comments were made indicating which part of the
		assignment corresponds to which part of the code

II. Bugs Encountered
	- The method Degree() will always return -1 in whichever ItemType when the LinkedPolynomial is empty. Potential Bugs:
		- This can be an error if -1 cannot be cast into the ItemType
		- This will be ambiguous when the Linked Polynomial contains only 1 entry whose exponent is -1
	- Difficulty was encountered when trying to find the last entry for Add()
		- I was doing while(cursor != nullptr) which means that cursor will always go to what the last entry points to which is NULL
		- The solution: while(cursor.GetNext() != nullptr) which gets the cursor whose next pointer points to NULL

III. Run Instructions
	- make
	- ./Polynomials

IV. Input/Output Files
	- none