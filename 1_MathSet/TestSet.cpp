/***************************************************************
Title:			TestSet.cpp
Author:			Michael Garod
Date Created:	2/12/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #1
Description:	Runs client functions to prove that class Set
				will function precisely as mathematical sets do
***************************************************************/

#include "Set.h"

int main()
{
	//TestSetImplementation<int>();
	
	//TestUniteSets<int>();

	Set<int> some_set(1, 5);
	some_set.add(2);
	some_set.add(3);
	some_set.add(4);
	some_set.add(5);

	Set<int>* ps = returnPowerSet(some_set);
	
	return 0;
}