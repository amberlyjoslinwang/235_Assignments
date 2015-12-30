/***************************************************************
Title:			README.txt
Author:			Michael Garod
Date Created:	4/22/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #3
Description:	Brief description containing which parts of the assignment were
				completed, bugs encountered, instructions on how to run
				the program, and input/output files necessary or created.
Contents:		This .zip file should contain this README.txt, makefile,
				LinkedStack.cpp, LinkedStack.h, Node.cpp, Node.h, PreconditionViolatedException.cpp, PreconditionViolatedException.h, InfixToPostfixCalculator.cpp, InfixToPostfixCalculator.h, infixFile, and Test.cpp
				(12 files total)
Note:			This project was built with base code provided by 
				Pearson Education, Inc. which can be found on their website.
***************************************************************/

I. Parts Completed
	- All required parts of assignment were completed
		- Extra credit was not attempted
	- Where applicable, comments were made indicating which part of the
		assignment corresponds to which part of the code

II. Bugs Encountered
	- Handling Decimal Points
		- ex. The Expression "12. * 3" converts to "12.,3,*" but
		the decimal should be discarded by human standards
		- Handling decimal points was the last feature implemented and may be the least complete. There probably exist some exception cases that are not handled properly.
		- The infix expression ".1.21 + 54.41" yields the postfix expression ".1,.21,54.41,+" which throws the exception "Postfix Expression has more numbers than operators" which is not true. In actuality the true exception is that there is a misplaced decimal point in the infix.
			- Solution would be to better interpret decimal numbers within InfixToPostfixCalculator::convertInfixToPostfix();
	- Order of Exception cases
		- When checking for exception cases on the infix expression, the least complex exceptions are checked first in order to save time.
		- May provide less accurate results by this order
	- Postfix Exception cases
		- By design, I would say >95% of potential exceptions are handled by the infix to postfix converter. If a postfix is successfully generated, the possibility for any further exceptions are very slim.
		- See "Handling Decimal Points" above for such a case
	- Build Warnings
		- Using an unsigned int for a while loop condition
			- while(unsigned int i >=0) is always true since unsigned ints cannot be strictly less than 0.
			- Solution: Static cast this unsigned int to a strict int

III. Run Instructions
	- make
	- ./Test
	- make clean

IV. Input/Output Files
	- Input: infixFile
	- Output: resultFile
		- Output file is created and will overwrite. It will NOT append.

V. General Comments
	I am not very proud of this assignment because of my poorly planned approach due to being overstressed and overworked. My normal approach is to think the entire problem through at a high abstract level, writing a skeleton program, and progressively fleshing out the code. For this program however I built it linearly, and so I continuously threw code at the program. The final product is inelegant, and perhaps unreadable.