/***************************************************************
Title:			README.txt
Author:			Michael Garod
Date Created:	5/15/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #4
Description:	Brief description containing which parts of the assignment were
				completed, bugs encountered, instructions on how to run
				the program, and input/output files necessary or created.
Contents:		This .zip file should contain 18 items:
				BinaryNode.h, BinaryNode.cpp,
				BinarySearchTree.h, BinarySearchTree.cpp, BinaryTreeInterface.h
				LinkedList.cpp, LinkedList.h, ListInterface.h
				MainBST.cpp
				Node.cpp, Node.h
				NotFoundException.cpp, NotFoundException.h
				PreconditionViolatedException.cpp, PreconditionViolatedException.h
				document1.txt, makefile, README.txt
Note:			This project was built with base code provided by 
				Pearson Education, Inc. which can be found on their website.
***************************************************************/

I. Parts Completed
	- All required parts of assignment were completed
		- Extra credit (g) was completed: removal of a word
		- Extra credit (h) was not completed
	- Was not technically a required part of the assignment (I believe), but the bottom of the pdf says to implement a copy-constructor, assignment operator, and destructor. They are also completed.
	- Where applicable, comments were made indicating which part of the
		assignment corresponds to which part of the code

II. Bugs Encountered
	- I was unsure if it was necessary to output the lexicographical traversal to an output file. Output will only print to console, which could be problematic for grading.
	- During build, a warning will be received for an inequality of a char and 255. This is designed to catch non-ASCII characters.

III. Run Instructions
	- make
	- ./MainBST
	- make clean

IV. Input/Output Files
	- Input: infixFile
	- Output: n/a