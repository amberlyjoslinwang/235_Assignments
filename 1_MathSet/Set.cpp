/***************************************************************
Title:			Set.cpp
Author:			Michael Garod
Date Created:	2/12/2015
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #1
Description:	Provides class methods and functions to be used to
				simulate ADT Set which acts like a mathematical set
Note:			DO NOT COMPILE Set.cpp. It is automatically
				included with Set.h (which is included by TestSet.cpp)
***************************************************************/

#include "Set.h"


/************Class Set Member Methods************/

// Description: Default Constructor which creates an empty set of
//		some ItemType whose max size is arbitrarily 4.
// Pre: none
// Post: Creates an empty set
template<class ItemType>
Set<ItemType>::Set()
{
	set_of_elements = NULL;
	size_of_set = 0;
	max_size = 4;
}


// Description: Constructor which creates an empty set of some ItemType
//		whose max size is defined by the integer argument.
// Pre: Accepts an integer argument to be the Set's max_size
// Post: Creates an empty set, whose maximum size is (int)size.
template<class ItemType>
Set<ItemType>::Set(int size)
{
	set_of_elements = NULL;
	size_of_set = 0;
	max_size = size;
}


// Description: Constructor which accepts an element of some ItemType,
//		and an integer to be the Set's maximum size.
// Pre: Accepts an argument equal to the ItemType used by the set
// Post: The set now contains exactly 1 element in an array[1]
template<class ItemType>
Set<ItemType>::Set(const ItemType& element, int size)
{
	set_of_elements = new ItemType[1];
	set_of_elements[0] = element;
	size_of_set = 1;
	max_size = size;
}


// Desciption: Member Method that prints out its own set in math notation
// Pre: none
// Post: none
template<class ItemType>
const void Set<ItemType>::printSet() const
{
	if (NULL == set_of_elements)
	{
		cout << "{empty set}\n";
		return;
	}

	for (int i = 0; i < size_of_set; i++)
	{
		if (0 == i)
		{	// First element print {
			cout << "{";
		}
		// Always print element
		cout << set_of_elements[i];

		if (size_of_set - 1 == i)
		{	// Last element print }
			cout << "}\n";
		}
		else
		{	// Always print comma if not last element
			cout << ",";
		}
	}
}


// Description: Answers the question "Is this set empty?"
// Pre: none
// Post: Returns true if yes. Returns false if no.
template<class ItemType>
bool Set<ItemType>::isEmpty() const
{
	if (0 == size_of_set)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Description: Answers the question "Does this set contain this element?"
// Pre: Accepts an argument equal to the ItemType used by the set
// Post: Returns true if yes. Returns false if no.
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& element) const
{
	bool found = false;
	int i = 0;
	while ((false == found) && (i < size_of_set))
	{
		if (set_of_elements[i] == element)
		{
			found = true;
		}
		i++;
	}

	return found;
}


// Description: Returns the index of an element within the set
// Pre: Accepts and argument equal to the ItemType used by the set
// Post: Returns index of the element argument. If element does not exist
//		within the set, return -1;
template<class ItemType>
const int Set<ItemType>::getIndexOf(const ItemType& element) const
{
	if (!contains(element))
	{	// element does not exist in the set
		return -1;
	}
	else
	{	// element is somewhere in the set
		for (int i = 0; i < size_of_set; i++)
		{
			if (set_of_elements[i] == element)
			{	// returns index of first found match
				return i;
			}
		}
		return -1;	// If element is somehow not found, will still return -1
	}
}


// Description: Adds an element to the set by expanding the size of the
//		set by 1. If addition would exceed max_size, addition does not occur.
//		If the set already contains the element, do nothing, return false.
// Pre: Accepts an argument equal to the ItemType used by the set
// Post: The set will contain the additional element, if legal.
template<class ItemType>
bool Set<ItemType>::add(const ItemType& element)
{
	if (contains(element))
	{	// If element already exists in our set, do nothing
		return false;
	}
	else if(size_of_set + 1 <= max_size)
	{	// Create new, larger array which will include element
		ItemType* temporary = new ItemType[size_of_set + 1];

		for (int i = 0; i < size_of_set; i++)
		{	// Copy set_of_elements to holding location
			temporary[i] = set_of_elements[i];
		}

		temporary[size_of_set] = element;
		
		delete[] set_of_elements;	// Delete the set before addition

		// set_of_elements now points to the larger, added array
		set_of_elements = temporary;

		size_of_set++;
		return true;
	}
	else
	{	// Exceeds max_size or is already inside the set
		return false;
	}
		
}


// Description: Removes an element from the set (if it exists), and alters
//		the set to be one element smaller so that there is no empty space.
//		If the element is not in the set, do nothing, return false.
//		If the element is only element in the set, create empty set.
// Pre: Accepts an argument equal to the ItemType used by the set
// Post: The set will no longer contain the element, and is 1 size smaller.
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& element)
{
	int index = getIndexOf(element);

	if (-1 == index)
	{ // The element being removed doesn't exist in the set
		return false;
	}
	else if (0 == size_of_set)
	{ // Cannot remove from an empty set
		return false;
	}
	else if (1 == size_of_set && contains(element))
	{ // Case when set has only 1 element, change to empty string
		this->clear();
		return true;
	}
	else
	{
		ItemType* temporary = new ItemType[size_of_set - 1];
		
		// i represents position in the temporary array
		// j represents position in the set array
		// Copy elements from set to temporary as long as it is not
		//  the element to be removed from the set.
		// If the removed element is encountered, skip it,
		//  then continue copying any remaining elements

		int j = 0;
		for (int i = 0; i < size_of_set-1; i++)
		{
			if (set_of_elements[j] != element)
			{
				temporary[i] = set_of_elements[j];
				j++;
			}
			else
			{
				i--;
				j++;
			}
		}

		delete[] set_of_elements;	// Delete the set before removal

		// set_of_elements now points to the smaller, removed array
		set_of_elements = temporary;

		size_of_set--;
		return true;
	}
	return false;
}


// Description: Gets the current size of set
// Pre: none
// Post: Returns size_of_set as int
template<class ItemType>
const int Set<ItemType>::getSizeOfSet() const
{
	return size_of_set;
}


// Description: Gets any element in the set
// Pre: int argument for the index of the set to be returned
// Post: Returns ItemType at the index
template<class ItemType>
const ItemType Set<ItemType>::getElement(int index) const
{
	if (index >= size_of_set)
	{
		return false;
	}
	return *(set_of_elements + index);
}


// Description: Setter for max_size of the set
// Pre: int argument to be new max_size
// Post: max_size is changed to int argument
template<class ItemType>
void Set<ItemType>::setMaxSize(const int& num)
{
	max_size = num;
}

// Description: Getter for max_size of the set
// Pre: none
// Post: none
template<class ItemType>
const int Set<ItemType>::getMaxSize() const
{
	return max_size;
}

// Description: Changes the set to an empty set
// Pre: none
// Post: The set is now an empty set of size 0
template<class ItemType>
void Set<ItemType>::clear()
{
	delete[] set_of_elements;
	set_of_elements = NULL;
	size_of_set = 0;
}



/***********Client Functions**********/

// Description: Performs the mathematical Union operation on two Set objects
// Pre: Accepts any two Set objects as arguments
// Post: Returns a single Set object equal to the Union of the arguments
template<class ItemType>
Set<ItemType> uniteSets(const Set<ItemType>& set1,
								const Set<ItemType>& set2)
{
	// Algorithm for a trivial union: Au0=A or 0uB=B
	if (0 == set1.getSizeOfSet() )
	{	// If set1 is empty, the union will be set2 regardless of set2
		return set2;
	}
	else if (0 == set2.getSizeOfSet())
	{	// If set2 is empty, the union will be set1 regardless of set1
		return set1;
	}

	// Algortihm to construct a non-trivial union
	int size_1 = set1.getSizeOfSet();
	int size_2 = set2.getSizeOfSet();
	Set<ItemType> unionSet(size_1 + size_2);

	for (int i = 0; i < size_1; i++)
	{	// At minimum, the union will be equal to Set1, so copy all elements
		unionSet.add(set1.getElement(i));
	}

	for (int i = 0; i < size_2; i++)
	{	// If set1 does not contain some element in set2, add it to union
		if (!unionSet.contains(set2.getElement(i)) )
		{
			unionSet.add(set2.getElement(i));
		}
	}

	return unionSet;
}


// Description: Client Function that prints out a set in math notation
// Pre: Accepts any Set object and will print its contents
// Post: none
template<class ItemType>
const void displaySet(const Set<ItemType>& a_set)
{
	int size = a_set.getSizeOfSet();

	if (0 == size)
	{
		cout << "{empty set}\n";
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (0 == i)
		{	// First element print {
			cout << "{";
		}
		// Print i'th element
		cout << a_set.getElement(i);

		if (size - 1 == i)
		{	// Last element print }
			cout << "}\n";
		}
		else
		{	// Always print comma if not last element
			cout << ",";
		}
	}
}

// Description: Tests Set objects as described in the assignment
// Pre: none
// Post: none
template<class ItemType>
void TestSetImplementation()
{
	// Part i & ii
	Set<ItemType> a_Set;
	a_Set.printSet();
	cout << "This is the empty set, and isEmpty() returns: " <<
		a_Set.isEmpty() << endl;	// 1
	cout << "a_Set.add(4) returns: " << a_Set.add(4) << endl; // 1
	cout << "a_Set.contains(4) returns: " << a_Set.contains(4)// 1
			<< endl << endl;

	// Part iii, iv, vii - Adding repetitive values
	cout << "Creating a new, empty set and adding {1,10,3,10,5,10} " <<
				"in that order\n";
	Set<ItemType> b_Set;
	cout << "b_Set.add(1) returns: " << b_Set.add(1) << endl;	// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1}
	cout << "b_Set.add(10) returns: " << b_Set.add(10) << endl;	// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,10}
	cout << "b_Set.add(3) returns: " << b_Set.add(3) << endl;	// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,10,3}
	cout << "b_Set.add(10) returns: " << b_Set.add(10) << endl;	// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,10,3}
	cout << "b_Set.add(5) returns: " << b_Set.add(5) << endl;	// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,10,3,5}
	cout << "b_Set.add(10) returns: " << b_Set.add(10) << endl;	// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,10,3,5}

	// Part v - Searching for elements within
	cout << "\nSearch for 4 in b_Set returns: " // 0
			<< b_Set.contains(4) << endl;
	cout << "Search for 10 in b_Set returns: "	// 1
			<< b_Set.contains(10) << endl;

	// Part vi - Adding beyond max capacity
	cout << "b_Set.add(2) returns: " << b_Set.add(2) << endl;
	cout << "b_Set currently contains : "; displaySet(b_Set);

	// Part viii & ix - Removing from a set, and an empty set
	cout << "\nRemoving elements {10, 3, 10, 1, 3, 5, 5, 20} in that order\n";
	cout << "b_Set.remove(10) returns: " << b_Set.remove(10) << endl;	// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,3,5}
	cout << "b_Set.remove(3) returns: " << b_Set.remove(3) << endl;		// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,5}
	cout << "b_Set.remove(10) returns: " << b_Set.remove(10) << endl;	// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {1,5}
	cout << "b_Set.remove(1) returns: " << b_Set.remove(1) << endl;		// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {5}
	cout << "b_Set.remove(3) returns: " << b_Set.remove(3) << endl;		// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {5}
	cout << "b_Set.remove(5) returns: " << b_Set.remove(5) << endl;		// 1
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {empty set}
	cout << "b_Set.remove(5) returns: " << b_Set.remove(5) << endl;		// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {empty set}
	cout << "b_Set.remove(20) returns: " << b_Set.remove(20) << endl;	// 0
	cout << "b_Set currently contains : "; displaySet(b_Set);	// {empty set}



}


// Description: Tests uniteSets() as described in the assignment
// Pre: none
// Post: none
template<class ItemType>
void TestUniteSets()
{
	// Part i
	cout << "\nCreating two empty sets\n";
	Set<ItemType> set1, set2;
	Set<ItemType> set3 = uniteSets(set1, set2);
	cout << "The Union of two empty sets is: "; displaySet(set3);//{empty set}

	// Part ii
	cout << "\nAdding {2,3} to set1: ";
	set1.add(2); set1.add(3); displaySet(set1);			// {2,3}
	cout << "Set2 remains empty: "; displaySet(set2);	// {empty set}
	set3 = uniteSets(set1, set2);
	cout << "The union of a non-empty set and an empty set\n" <<
		"\tis simply the non-empty set: "; displaySet(set3);	// {2,3}

	// Part iii
	cout << "\nAdding {4,5} to set2: ";
	set2.add(4); set2.add(5); displaySet(set2);			// {4,5}
	cout << "Set1 remains the same: "; displaySet(set1);// {2,3}
	set3 = uniteSets(set1, set2);						// {2,3,4,5}
	cout << "The Union of two sets whose intersection is empty\n" <<
		"\tis the concatenation of the sets: "; displaySet(set3);
	
	// Part iv
	set1.clear();		// revert to empty sets
	set2.clear();
	cout << "\nEmptying Set1 and Set2\n";
	cout << "Adding {7,8,9} to Set1, {8,9,10} to Set2\n";
	set1.add(7); set1.add(8); set1.add(9);			// {7,8,9}
	set2.add(8); set2.add(9); set2.add(10);			// {8,9,10}
	set3 = uniteSets(set1, set2);					// {7,8,9,10}
	cout << "The union of two sets with common elements is the set\n" <<
		"\tof elements that exist in Set1 OR Set2: "; displaySet(set3);
}

/*
// Description: Power Set
// Pre: 
// Post: 
template<class ItemType>
Set<ItemType>* returnPowerSet(const Set<ItemType>& set1)
{
	int set_size = set1.getSizeOfSet();
	int two_to_the_n = static_cast<int>( pow(2, set_size) );
	
	// The Power Set must be a set of size 2^n,
	// where each element is a set (called set-element)
	// This is initialized for every set-element to be the empty set
	Set<ItemType>* powerSet = new Set<ItemType>[two_to_the_n];

	for (int i = 0; i < two_to_the_n; i++)
	{
		powerSet[i].setMaxSize(two_to_the_n);
	}

	// Building a Power Set starting with an empty set,
	// and continuously uniting single elements
	for (int set_index = 0; set_index < set_size; set_index++)
	{	// set_index controls which elements to unite into the Power Set

		// current_ps_max determines how many elements to unite into the P.S.
		int current_ps_max = static_cast<int>( pow(2, set_index) );
		cout << "current_ps_max: " << current_ps_max << endl;

		// Element at set1[set_index] is made into a singleton set
		// for the purposes of uniting into the Power Set
		Set<ItemType> singleton( set1.getElement(set_index), two_to_the_n );
		cout << "element to add: "; singleton.printSet();

		// Copy all set-elements from powerSet[0] to powerSet[current_ps_max]
		// into powerSet[current_ps_max+1] to powerSet[2*current_ps_max]
		// because the next power-set-elements will be identical, except with
		// the union of the next single set-element(singleton)
		for (int copy_index = 0; copy_index < current_ps_max; copy_index++)
		{
			Set<ItemType> whatever = uniteSets(powerSet[copy_index], singleton);
			cout << "whatever: "; whatever.printSet();

			powerSet[current_ps_max + copy_index] =
				uniteSets(powerSet[copy_index], singleton);

			cout << "copy_index: " << copy_index << endl;

			displaySet(powerSet[current_ps_max + copy_index]);
		}
	}

	for (int i = 0; i <= two_to_the_n; i++)
	{
		//cout << "method: " << i << " ";  powerSet[i].printSet();
		//cout << "function: " << i << " ";  displaySet(powerSet[i]);
	}

	return powerSet;
}*/


// Description: Constructs the power set inductively beginning with the empty
//		set. Every subsequent power-set-element is constructed by uniting
//		singleton sets taken from  with previous power-set-elements
// Pre: 
// Post: 
template<class ItemType>
Set<ItemType>* returnPowerSet(const Set<ItemType>& set1)
{
	// These are generalized parameters for any Power Set
	int set_size = set1.getSizeOfSet();
	int two_to_the_n = static_cast<int>( pow(2, set_size) );
	
	// The Power Set must be a set of size 2^n,
	// where each element is a set (called set-element)
	// This is initialized for every set-element to be the empty set
	Set<ItemType>* powerSet = new Set<ItemType>[two_to_the_n];

	// Building a Power Set starting with an empty set,
	// and continuously uniting single elements
	for (int set_index = 0; set_index < set_size; set_index++)
	{	// set_index controls which elements to unite into the Power Set

		// current_ps_max determines how many elements to unite into the P.S.
		int current_ps_max = static_cast<int>( pow(2, set_index) );
		
		// Element at set1[set_index] is made into a singleton set
		// for the purposes of uniting into the Power Set
		Set<ItemType> singleton( set1.getElement(set_index), two_to_the_n );

		// Copy all set-elements from powerSet[0] to powerSet[current_ps_max]
		// into powerSet[current_ps_max+1] to powerSet[2*current_ps_max]
		// because the next power-set-elements will be identical, except with
		// the union of the next single set-element(singleton)
		for (int copy_index = 0; copy_index < current_ps_max; copy_index++)
		{
			powerSet[current_ps_max + copy_index] =
				uniteSets(powerSet[copy_index], singleton);

			displaySet(powerSet[current_ps_max + copy_index]);
		}
	}

	return powerSet;
}