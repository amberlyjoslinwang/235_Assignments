/******************************************************
Title:			LinkedPolynomial.cpp
Author:			Michael Garod
Date Created:	3/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #2
Description:	Implementation file of LinkedPolynomial class.
				This is merely a modification of the provided
				ADT LinkedBag class on BlackBoard
Modifications:	Add(), AddPolynomial(), DisplayPolynomial(), Degree(),
				Coefficient(), ChangeCoefficient(), Contains()
******************************************************/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos.

/** ADT bag: Link-based implementation.
	@file LinkedPolynomial.cpp */

#include "LinkedPolynomial.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial() : head_ptr_(NULL), item_count_(0)
{
}  

template<class ItemType>
LinkedPolynomial<ItemType>::LinkedPolynomial(const LinkedPolynomial<ItemType>& a_bag)
{
  CopyNodesFrom(a_bag);
}  

template<class ItemType>
LinkedPolynomial<ItemType>& LinkedPolynomial<ItemType>::operator=(const LinkedPolynomial<ItemType>& right_hand_side) {
  if (this != &right_hand_side) {  
	Clear(); // First deallocate all memory.
	CopyNodesFrom(right_hand_side);  // Then copy everything.
  }
  return *this;  // Return self.
}

template<class ItemType>
LinkedPolynomial<ItemType>::~LinkedPolynomial()
{
  Clear();
}  

template<class ItemType>
bool LinkedPolynomial<ItemType>::IsEmpty() const
{
  return item_count_ == 0;
}  

template<class ItemType>
int LinkedPolynomial<ItemType>::GetCurrentSize() const
{
  return item_count_;
}  


/**** PAGE 1 PART B SECTION ii --- CHANGE TO ADD AT END OF LIST
	NOW TAKES TWO PARAMETERS, coefficient and exponent
	IF EXPONENT ALREADY EXISTS, DO NOT CHANGE ANYTHING ****/
// Description: If we're adding an exponent we already have, do nothing.
//				Else, 
template<class ItemType>
bool LinkedPolynomial<ItemType>
		::Add(const ItemType& new_coefficient, const ItemType& new_exponent)
{
	if (Contains(new_exponent))
	{	
		// If our poly has already has exponent, make no change
		return false;
	}

	// Here is our new entry
	Node<ItemType>* newNodePtr = new Node<ItemType>;
	newNodePtr->SetCoefficient(new_coefficient);
	newNodePtr->SetExponent(new_exponent);
	newNodePtr->SetNext(NULL);

	if (head_ptr_ == NULL)
	{	// Case for empty list (first entry)
		head_ptr_ = newNodePtr;
		item_count_++;
		return true;
	}

	// Finding the last node
	Node<ItemType>* cursor = head_ptr_;

	while (NULL != cursor->GetNext() )
	{	
		cursor = cursor->GetNext();
	}

	//cout << "cursor coef: " << cursor->GetCoefficient() << endl;
	//cout << "cursor exp: " << cursor->GetExponent() << endl;

	cursor->SetNext(newNodePtr);
	// cout << "cursor coef: " << cursor->GetCoefficient() << endl;
	// cout << "cursor exp: " << cursor->GetExponent() << endl;

  item_count_++;
  return true;
}  

// Description: Destructor
template<class ItemType>
void LinkedPolynomial<ItemType>::Clear()
{
  Node<ItemType>* current_node_to_delete = head_ptr_;
  while (head_ptr_ != NULL) {
	head_ptr_ = head_ptr_->GetNext();
	// Return node to the system
	current_node_to_delete->SetNext(NULL);
	delete current_node_to_delete;
	current_node_to_delete = head_ptr_;  // Move to the next one.
  }  // end while
  item_count_ = 0;
}  

// Description: Never used in LinkedPolynomial
template<class ItemType>
int LinkedPolynomial<ItemType>::GetFrequencyOf(const ItemType& an_entry) const
{
  int frequency = 0;
  int counter = 0;
  Node<ItemType>* current_ptr = head_ptr_;
  while (current_ptr != NULL){
	if (an_entry == current_ptr->GetItem()) {
	  frequency++;
	} // end if
	counter++;
	current_ptr = current_ptr->GetNext();
	// Check for possible serious error.
	if (counter > item_count_) {
	   cout << "Serious error in LinkedPolynomial<ItemType>::GetFrequencyOf" << endl;
	   return frequency;
	}
  } // end while
  return frequency;
} 


// Description: Completely changed from LinkedBag. Only searches exponents.
//				Iterate through all nodes. If we find an exponent match,
//				return true. Else, return false.
//				Modification was necessary because we do not want two Nodes
//				with identical exponents.
template<class ItemType>
bool LinkedPolynomial<ItemType>::Contains(const ItemType& an_entry) const
{	// We only care if it contains a certain EXPONENT
	bool found = false;
	Node<ItemType>* cursor = head_ptr_;

	while (!found && (cursor != NULL))
	{
		if (an_entry == cursor->GetExponent())
		{
			found = true;
		}
		else
		{
			cursor = cursor->GetNext();
		}
	}

	return found;
	
   // This is the original LinkedBag implementation of Contains()
   // Removed this because I was having a lot of trouble with it.

   // return (GetPointerTo(an_entry) != NULL);
}  // end Contains


// Description: No modifications from LinkedBag.
template<class ItemType>
Node<ItemType>* LinkedPolynomial<ItemType>::GetPointerTo(const ItemType& an_entry) const
{
   Node<ItemType> *current_ptr = head_ptr_;

   while (current_ptr != NULL) {
	
	 if (an_entry == current_ptr->GetExponent() )
	 {
	   return current_ptr;
	 }
	 else
	 {
	   current_ptr = current_ptr->GetNext();
	 }
   } // end while 
   return NULL;
} 

// Description: Copy constructor. Virtually no modifications from LinkedBag.
//				Change was from a single item to two items (exp and coef)
template<class ItemType>
void LinkedPolynomial<ItemType>::CopyNodesFrom(const LinkedPolynomial<ItemType> &a_bag) {
  item_count_ = a_bag.item_count_;  
  Node<ItemType>* a_bag_current_pointer = a_bag.head_ptr_;  // Pointer to beginning of a_bag.
   
  if (a_bag_current_pointer == NULL) {  // a_bag is empty.
	head_ptr_ = NULL;  
	return;
  } 
  // Copy first node
  head_ptr_ = new Node<ItemType>();
  head_ptr_->SetExponent(a_bag_current_pointer->GetExponent());
  head_ptr_->SetCoefficient(a_bag_current_pointer->GetCoefficient());
  
  // Copy remaining nodes
  Node<ItemType>* last_pointer = head_ptr_;      // Points to last node in new chain
  a_bag_current_pointer = a_bag_current_pointer->GetNext();     // Advance original-chain pointer
  
  while (a_bag_current_pointer != NULL) {
	// Create a new node holding the item of a_bag_current_pointer.
	  Node<ItemType>* new_node_pointer = new Node<ItemType>();
	  new_node_pointer->SetExponent(a_bag_current_pointer->GetExponent());
	  new_node_pointer->SetCoefficient(a_bag_current_pointer->GetCoefficient());
	
	// Link new node to end of new chain
	last_pointer->SetNext(new_node_pointer);
	
	// Advance pointer to new last node
	last_pointer = last_pointer->GetNext();
	
	// Advance original-chain pointer
	a_bag_current_pointer = a_bag_current_pointer->GetNext();
  }  // end while
  last_pointer->SetNext(NULL); 
}

// Description: Displays content of the polynomial without regard
//				for order of the terms
template<class ItemType>
void LinkedPolynomial<ItemType>::DisplayPolynomial() const
{
	/************************
	PAGE 2 PART B SECTION iii
	-3 * x^ 7 + 4.1 * x^ 5 + 7 * x^3 + 9 * x^0
	Cout the human form of the polynomial
	************************/

	// Empty Polynomial? show zeroes, then return
	if (IsEmpty() )
	{
		cout << "0*x^0" << endl;
		return;
	}

	Node<ItemType>* cursor = head_ptr_;
	
	while (cursor->GetNext() != NULL)
	{	// For Poly of n terms, cout terms 1 through n-1
		cout << cursor->GetCoefficient() << "*x^" << cursor->GetExponent() << " + ";
		cursor = cursor->GetNext();
	}
	
	// Special case for nth term which won't have a trailing "+"
	cout << cursor->GetCoefficient() << "*x^" << cursor->GetExponent() << endl;
	
}


template<class ItemType>
ItemType LinkedPolynomial<ItemType>::Degree() const
{
	/*****
	PAGE 2 PART B SECTION iv
	RETURN HIGHEST EXPONENT/DEGREE OF POLYNOMIAL or -1 if empty
	*****/
	
	ItemType highestDegree = -1;

	// Empty Polynomial?
	if (IsEmpty())
	{
		return highestDegree;
	}

	// Search for Highest Degree
	Node<ItemType>* cursor = head_ptr_;

	while (cursor != NULL)
	{
		if (cursor->GetExponent() > highestDegree)
		{
			highestDegree = cursor->GetExponent();
		}
		cursor = cursor->GetNext();
	}

	return highestDegree;
}



template<class ItemType>
ItemType LinkedPolynomial<ItemType>
		::Coefficient(const ItemType& exponent) const
{
	/*****
	PAGE 2 PART B SECTION v
	RETURNS COEFFICIENT OF THE ARGUMENT EXPONENT, 0 if DOES NOT EXIST
	*****/

	// If polynomial doesn't contain that exponent, then coefficient is 0
	if (Contains(exponent) == false)
	{
		return 0;
	}

	// Find exponent
	return (GetPointerTo(exponent)->GetCoefficient());
}


template<class ItemType>
bool LinkedPolynomial<ItemType>
		::ChangeCoefficient(ItemType new_coefficient, ItemType exponent)
{
	/*****
	PAGE 2 PART B SECTION vi
	RETURNS TRUE IF THE EXPONENT EXISTS AND WAS CHANGED
	RETURNS FALSE IF EXPONENT DOES NOT EXIST
	*****/

	// If polynomial doesn't contain that exponent, can't change coefficient
	if (Contains(exponent) == false)
	{
		return false;
	}

	// Find exponent, set new_coefficient
	GetPointerTo(exponent)->SetCoefficient(new_coefficient);
	return true;
}


template<class ItemType>
void LinkedPolynomial<ItemType>
		::AddPolynomial(const LinkedPolynomial<ItemType>& b_polynomial)
{
	/*****
	Add another polynomial to this.polynomial
	
	this.polynomial = another.polynomial + this.polynomial

	RETURN VOID
	*****/

	// Trivial Cases
	// Case if either is empty
	if (b_polynomial.IsEmpty() == true)
	{
		return;
	}
	else if (IsEmpty() == true)
	{
		CopyNodesFrom(b_polynomial);
		return;
	}

	// Non-Trivial cases
	// Does A contain an exponent that B has?
	// Case Yes: If yes, add B coefficient to A coefficient
	// Case No: If no, add B Node to A polynomial.
	Node<ItemType>* cursor = b_polynomial.head_ptr_;
	
	while (cursor != NULL)
	{
		// These are the exponent and coefficent of cursor on b_polynomial
		ItemType b_exponent = cursor->GetExponent();
		ItemType b_coefficient = cursor->GetCoefficient();

		// Case Yes
		if (Contains(b_exponent) )
		{
			ItemType new_coefficient = b_coefficient + Coefficient(b_exponent);
			ChangeCoefficient(new_coefficient, b_exponent);
		}
		// Case No
		else
		{
			Add(b_coefficient, b_exponent);
		}

		cursor = cursor->GetNext();
	}

}
