/***************************************************************
Title:			Set.h
Author:			Michael Garod
Date Created:	2/12/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #1
Description:	Provides declarations for class Set and other
				functions to simulate ADT Set which acts like a
				mathematical set
***************************************************************/

#ifndef SET_H
#define SET_H

#include <iostream>
#include <cmath>
using namespace std;

// Class Declaration
template<class ItemType> 
class Set
{
	public:
		Set();		// empty set of max size 4
		Set(int);	// empty set of max size int
		Set(const ItemType&, int);	// Singleton set of max size int
		const void printSet() const;
		bool isEmpty() const;
		bool contains(const ItemType&) const;	// "is an element of"
		const int getIndexOf(const ItemType&) const;
		bool add(const ItemType&);
		bool remove(const ItemType&);
		const int getSizeOfSet() const;
		const ItemType getElement(int) const;
		void setMaxSize(const int&);
		const int getMaxSize() const;
		void clear();

	private:
		ItemType* set_of_elements;
		int size_of_set;
		int max_size;		// Default Constructor sets 4
};

// Client Functions
template<class ItemType>
Set<ItemType> uniteSets(const Set<ItemType>&,
								const Set<ItemType>&);

template<class ItemType>
const void displaySet(const Set<ItemType>&);

template<class ItemType>
void TestSetImplementation();

template<class ItemType>
void TestUniteSets();

template<class ItemType>
Set<ItemType>* returnPowerSet(const Set<ItemType>&);

#include "Set.cpp"

#endif