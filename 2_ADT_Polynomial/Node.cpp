/******************************************************
Title:			Node.cpp
Author:			Michael Garod
Date Created:	3/14/15
Class:			Spring 2015, CSCI 235-01, Tues & Fri 12:45pm-2:00pm
Professor:		Ilya Korsunsky
Purpose:		Assignment #2
Description:	Implementation file of Node class. This is merely
				a modification of the provided ADT LinkedBag
				class provided on BlackBoard.
Modifications:	Nodes now hold 2 items, and have proper getters and setters
				for each of them.
Modifications:	GetExponent(), SetExponent(), GetCoefficient(),
				SetCoefficent()
******************************************************/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.cpp 
	Listing 4-2 */


#include "Node.h"
#include <cstddef>


// Default Constructor
template<class ItemType>
Node<ItemType>::Node() : next_node_(NULL)
{
} // end default constructor


// Copy Constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item) :
	exponent_(an_item), next_node_(NULL)
{
} // end constructor
  

// Copy Constructor - Exponent & Next Node
template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item, Node<ItemType>* next_node) :
	exponent_(an_item), next_node_(next_node)
{
} // end constructor


// // Setter: this node
// template<class ItemType>
// void Node<ItemType>::SetItem(const ItemType& an_item)
// {
//    item_ = an_item;
// } // end setItem

// Setter: this coefficient
template<class ItemType>
void Node<ItemType>::SetCoefficient(const ItemType& an_item)
{
   coefficient_ = an_item;
} // end setCoefficient

// Setter: this node
template<class ItemType>
void Node<ItemType>::SetExponent(const ItemType& an_item)
{
   exponent_ = an_item;
} // end setExponent

// Setter: next node
template<class ItemType>
void Node<ItemType>::SetNext(Node<ItemType>* next_node)
{
   next_node_ = next_node;
} // end setNext_Node_Ptr


// Getter: coefficient
template<class ItemType>
ItemType Node<ItemType>::GetCoefficient() const
{
   return coefficient_;
} // end getCoefficient


// Getter: exponent
template<class ItemType>
ItemType Node<ItemType>::GetExponent() const
{
   return exponent_;
} // end getExponent

// Getter: 
template<class ItemType>
Node<ItemType>* Node<ItemType>::GetNext() const
{
   return next_node_;
} // end getNext_Node_Ptr
