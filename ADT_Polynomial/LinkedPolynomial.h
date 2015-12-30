/******************************************************
Title:			Node.cpp
Author:			Michael Garod
Date Created:	3/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #2
Description:	Header file of LinkedPolynomial class. This is merely
				a modification of the provided ADT LinkedBag
				class provided on BlackBoard.
Modifications:	Add(), AddPolynomial(), DisplayPolynomial(), Degree(),
				Coefficient(), ChangeCoefficient(), Contains()
******************************************************/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.

/** ADT bag: Link-based implementation.
	@file LinkedPolynomial.h 
	Listing 4-3 */
#ifndef TEACH_CSCI235_LinkedPolynomial_LinkedPolynomial_H_
#define TEACH_CSCI235_LinkedPolynomial_LinkedPolynomial_H_

//#include "BagInterface.h"
#include "Node.h"
#include <iostream>
using namespace std;

// Linked-based implementation of the Bag ADT.
// Sample usage:
//    LinkedPolynomial<int> a_bag;
//    while (read a_value)
//        a_bag.Add(a_value);
//    if (a_bag.Contains(10))
//      cout << "10 is in the bag" << endl;
//    else
//      cout << "10 is not in the bag" << endl;
//    cout << "Frequency of 20 is " << a_bag.GetFrequencyOf(20) << endl;
//    const vector<int> a_vector = a_bag.ToVector();
//    /* Note C++11 syntax for accessing elements of vectors here*/
//    for (const auto &element: a_vector)
//       cout << element << " ";
//    cout << endl;
template<class ItemType>
class LinkedPolynomial //: public BagInterface<ItemType>
{
public:
   LinkedPolynomial();
   LinkedPolynomial(const LinkedPolynomial<ItemType>& a_bag); // Copy constructor.
   LinkedPolynomial<ItemType>& operator=(const LinkedPolynomial<ItemType>& right_hand_side); // Overloading of the assignment operator.
   virtual ~LinkedPolynomial();                       // Destructor should be virtual
   int GetCurrentSize() const;
   bool IsEmpty() const;
   bool Add(const ItemType& new_exponent, const ItemType& new_coefficient);
   void Clear();
   bool Contains(const ItemType& an_entry) const;
   int GetFrequencyOf(const ItemType& an_entry) const;
   void DisplayPolynomial() const;
   ItemType Degree() const;
   ItemType Coefficient(const ItemType& exponent) const;
   bool ChangeCoefficient(ItemType new_coefficient, ItemType Exponent);
   void AddPolynomial(const LinkedPolynomial<ItemType>& b_polynomial);

private:
   Node<ItemType>* head_ptr_; // Pointer to first node
   int item_count_;           // Current count of bag items
   
   // @return either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* GetPointerTo(const ItemType& target) const;
   
   // @param a_bag a given bag.
   // Allocates space and copies all the nodes from a_bag.
   // The function does not check whether this bag contains
   // any items, but it assumes that it is empty.
   void CopyNodesFrom(const LinkedPolynomial<ItemType> &a_bag);
}; // end LinkedPolynomial

#include "LinkedPolynomial.cpp"
#endif  // TEACH_CSCI235_LinkedPolynomial_LinkedPolynomial_H_
