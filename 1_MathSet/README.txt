/***************************************************************
Title:			README.txt
Author:			Michael Garod
Date Created:	2/16/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #1
Description:	Brief description containing which parts of the assignment were
				completed, bugs encountered, instructions on how to run
				the program, and input/output files necessary or created.
Contents:		This .zip file should contain this README.txt, makefile,
				Set.cpp, Set.h, and TestSet.cpp.
***************************************************************/

I. Parts Completed
	- All parts of assignment were completed
	- Where applicable, comments were made indicating which part of the
		assignment corresponds to which part of the code

II. Bugs Encountered
	- When I returned the unionSet in uniteSets(), I failed to see that
		I was returning a default constructed set, which meant it had
		the arbitrary, default max size of 4.
	Solution: Set<ItemType> unionSet(size_1 + size_2); which is the max size
			that any Union can possibly be when the intersection is empty.

III. Run Instructions
	- make
	- ./TestSet

IV. Input/Output Files
	- none