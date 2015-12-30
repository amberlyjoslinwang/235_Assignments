//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 
#include <algorithm>

// template<class ItemType>
// BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
// {
//    root_ = this->copyTree(treePtr.root_); // Call inherited method
// }  // end copy constructor

template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>::BinarySearchTree(const BinarySearchTree<ItemType, OtherType>& tree)
{
  root_ = CopyTree(tree.root_);
}  // end copy constructor

template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>& BinarySearchTree<ItemType, OtherType>::operator=(const BinarySearchTree<ItemType, OtherType>& right_hand_side)
{
	if (this != &right_hand_side) {
		Clear();
		root_ = CopyTree(right_hand_side.root_);
	}

	return *this; 
}  // end operator=


template<class ItemType, class OtherType>
BinarySearchTree<ItemType, OtherType>::~BinarySearchTree()
{
   DestroyTree(root_);
}  // end destructor


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::IsEmpty() const
{
   return root_ == nullptr;
}  // end isEmpty

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetHeight() const
{
   return GetHeightHelper(root_);
}  // end getHeight

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetNumberOfNodes() const
{
   return GetNumberOfNodesHelper(root_);
}  // end getNumberOfNodes

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Clear()
{
   DestroyTree(root_);
   root_ = nullptr;
}  // end clear



/****************************/


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Remove(const ItemType& target)
{
	removeHelper(target, root_);
  return false;
}  // end remove





/**************************/
template<class ItemType, class OtherType>
OtherType BinarySearchTree<ItemType, OtherType>::GetOther(const ItemType& an_entry) const throw(NotFoundException)
{
  cout << "Incomplete GetOther" << endl;  

  return OtherType();
}  // end getEntry

template<class ItemType, class OtherType>
OtherType& BinarySearchTree<ItemType, OtherType>::GetOtherReference(const ItemType& an_entry) throw(NotFoundException)
{
  cout << "Incomplete GetOtherReference" << endl;

  return OtherType();
}  // end getEntry

template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>:: Contains(const ItemType& an_entry) const
{
	if (FindNode(root_, an_entry) != nullptr)
	{
		return true;
	}

	return false;
}  // end contains


template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::printFullIndex() const
{
	printFullIndexHelper(root_);
}


template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::findMostFrequent() const
{
	return findMostFrequentHelper(root_);
}


template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::PreorderTraverse(void visit(ItemType&)) const
{
   Preorder(visit, root_);
}  // end preorderTraverse

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::InorderTraverse(void visit(ItemType&)) const
{
   Inorder(visit, root_);
}  // end inorderTraverse

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::PostorderTraverse(void visit(ItemType&)) const
{
   Postorder(visit, root_);
}  // end postorderTraverse



//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetHeightHelper(BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr == nullptr)
	  return 0;
   else
	  return 1 + max(GetHeightHelper(node_ptr->GetLeftPtr()), 
					 GetHeightHelper(node_ptr->GetRightPtr()));
}  // end GetHeightHelper

template<class ItemType, class OtherType>
int BinarySearchTree<ItemType, OtherType>::GetNumberOfNodesHelper(BinaryNode<ItemType, OtherType>* node_ptr) const
{

  if (node_ptr == nullptr)
  {
	  return 0;
  }

  return 1 + GetNumberOfNodesHelper(node_ptr->GetLeftPtr()) + GetNumberOfNodesHelper(node_ptr->GetRightPtr());
}  // end GetNumberOfNodesHelper


template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::printFullIndexHelper(BinaryNode<ItemType,OtherType>* nodePtr) const
{
	if (nodePtr != nullptr)
	{
		printFullIndexHelper(nodePtr->GetLeftPtr());

		int count = nodePtr->GetOther().GetLength();
		cout << nodePtr->GetItem() << "  Count: " << count;
		cout << " Lines:  ";

		for (int i = 1; i <= count; i++)
		{
			cout << nodePtr->GetOther().GetEntry(i) << ", ";
		}
		cout << endl;

		printFullIndexHelper(nodePtr->GetRightPtr());
	}
}


template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::
			findMostFrequentHelper(BinaryNode<ItemType, OtherType>* nodePtr) const
{
	int nodefrequency = nodePtr->GetOther().GetLength();

	// Case if no children
	if (nodePtr->IsLeaf())
	{
		return nodePtr;
	}
	// Case if only right child
	else if (nodePtr->GetLeftPtr() == nullptr && nodePtr->GetRightPtr() != nullptr)
	{
		BinaryNode<ItemType, OtherType>* right_mfreq = findMostFrequentHelper(nodePtr->GetRightPtr());
		int rightfrequency = right_mfreq->GetOther().GetLength();
		if (rightfrequency > nodefrequency)
		{
			return right_mfreq;
		}
		else
			return nodePtr;
	}
	// Case if only left child
	else if (nodePtr->GetRightPtr() == nullptr && nodePtr->GetLeftPtr() != nullptr)
	{
		BinaryNode<ItemType, OtherType>* left_mfreq = findMostFrequentHelper(nodePtr->GetLeftPtr());
		int leftfrequency = left_mfreq->GetOther().GetLength();

		if (leftfrequency > nodefrequency)
		{
			return left_mfreq;
		}
		else
			return nodePtr;
	}
	// Case if two children
	BinaryNode<ItemType, OtherType>* left_mfreq = findMostFrequentHelper(nodePtr->GetLeftPtr());
	BinaryNode<ItemType, OtherType>* right_mfreq = findMostFrequentHelper(nodePtr->GetRightPtr());
	
	int leftfrequency = left_mfreq->GetOther().GetLength();
	int rightfrequency = right_mfreq->GetOther().GetLength();

	if (rightfrequency > nodefrequency && rightfrequency > leftfrequency)
	{
		return right_mfreq;
	}
	else if (leftfrequency > nodefrequency && leftfrequency > rightfrequency)
	{
		return left_mfreq;
	}
	else // In case of tied equality, always select the nodePtr as the most frequent
	{
		return nodePtr;
	}
}


template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::findItem
					(const ItemType& an_item) const
{
	return FindNode(root_, an_item);
}


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Add(const ItemType& new_item, const OtherType& new_other)
{
   // Search the tree for this word
   // If it is in the tree, just add the line number to the existing node
	BinaryNode<ItemType, OtherType>* searchptr = FindNode(root_, new_item);
	
   if (searchptr != nullptr)
   {
	   int position = searchptr->GetOther().GetLength() + 1;
	   searchptr->GetOtherReference().Insert(position, new_other.GetEntry(1));
	   
	   return true;
   }

   // Else, add normally
   BinaryNode<ItemType, OtherType>* new_node = new BinaryNode<ItemType, OtherType>(new_item);
   new_node->SetOther(new_other);

   root_ = InsertInorder(root_, new_node);

   return true;
}  // end add


//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::InsertInorder(BinaryNode<ItemType, OtherType>* subTreePtr,
											  BinaryNode<ItemType, OtherType>* newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else if (subTreePtr->GetItem() > newNodePtr->GetItem())
	{
		BinaryNode<ItemType, OtherType>* tempPtr = InsertInorder(subTreePtr->GetLeftPtr(), newNodePtr);
		subTreePtr->SetLeftPtr(tempPtr);
	}
	else // if (subTreePtr->GetItem() < newNodePtr->GetItem())
	{
		BinaryNode<ItemType, OtherType>* tempPtr = InsertInorder(subTreePtr->GetRightPtr(), newNodePtr);
		subTreePtr->SetRightPtr(tempPtr);
	}

	return subTreePtr;
}  // end insertInorder



/*************************************/
// Finds the smallest value in the right subtree
template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::findInOrderSucc(
				BinaryNode<ItemType, OtherType>* rootptr) const
{
	return findSmallest(rootptr->GetRightPtr());
}

// Finds the smallest value in the given tree
template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::findSmallest(
				BinaryNode<ItemType, OtherType>* rootptr) const
{
	BinaryNode<ItemType, OtherType>* smallest = rootptr;

	while (smallest->GetLeftPtr() != NULL)
	{
		smallest = smallest->GetLeftPtr();
	}

	return smallest;
}

// Finds the smallest value in the right subtree
template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::removeHelper(const ItemType& val,
	BinaryNode<ItemType, OtherType>* nodeptr) const
{
	if (nodeptr == nullptr)
	{
		return nullptr;
	}
	else if (val == nodeptr->GetItem())
	{
		if (nodeptr->IsLeaf())
		{	// 0 children, simply delete the leaf, no rearrangement necessary
			delete nodeptr;
			nodeptr = nullptr;
			return nodeptr;
		}
		else if (nodeptr->GetLeftPtr() != nullptr && nodeptr->GetRightPtr() != nullptr)
		{	// 2 children
			BinaryNode<ItemType, OtherType>* inorder_successor = findInOrderSucc(nodeptr);
			nodeptr->SetItem(inorder_successor->GetItem());
			nodeptr->SetOther(inorder_successor->GetOther());
			delete inorder_successor;
			inorder_successor = nullptr;
			return nodeptr;
		}
		else
		{	// 1 child
			BinaryNode<ItemType, OtherType>* tempptr;

			if (nodeptr->GetLeftPtr() != nullptr)
			{
				tempptr = nodeptr->GetLeftPtr();
			}
			else // if (nodeptr->GetRightPtr() != nullptr)
			{
				tempptr = nodeptr->GetLeftPtr();
			}

			delete nodeptr;
			nodeptr = nullptr;
			return tempptr;
		}
	}
	else if (val < nodeptr->GetItem())
	{
		nodeptr->SetLeftPtr(removeHelper(val, nodeptr->GetLeftPtr()));
		return nodeptr;
	}
	else // if (val > nodeptr->GetItem())
	{
		nodeptr->SetRightPtr(removeHelper(val, nodeptr->GetRightPtr()));
		return nodeptr;
	}
}
/*******************************/

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::FindNode(BinaryNode<ItemType, OtherType>* subTreePtr,
														   const ItemType& target) const 
{
  if (subTreePtr == nullptr)
  {
	  return nullptr;
  }
  else if (subTreePtr->GetItem() == target)
  {
	  return subTreePtr;
  }
  else if (subTreePtr->GetItem() > target)
  {
	  return FindNode(subTreePtr->GetLeftPtr(), target);
  }
  else // if (subTreePtr->GetItem() < target)
  {
	  return FindNode(subTreePtr->GetRightPtr(), target);
  }
}  // end findNode

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::CopyTree(const BinaryNode<ItemType, OtherType>* node_ptr) const
{
   BinaryNode<ItemType, OtherType>* new_tree_ptr = nullptr;
   // Copy tree nodes during a preorder traversal
   if (node_ptr != nullptr) { 
	 // Copy node
	 new_tree_ptr = new BinaryNode<ItemType, OtherType>(node_ptr->GetItem());
	 new_tree_ptr->SetOther(node_ptr->GetOther());

	 new_tree_ptr->SetLeftPtr(CopyTree(node_ptr->GetLeftPtr()));
	 new_tree_ptr->SetRightPtr(CopyTree(node_ptr->GetRightPtr()));
   }  // end if
   return new_tree_ptr;
}  // end copyTree

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::DestroyTree(BinaryNode<ItemType, OtherType>* node_ptr)
{
   if (node_ptr != nullptr) {
	  DestroyTree(node_ptr->GetLeftPtr());
	  DestroyTree(node_ptr->GetRightPtr());
	  delete node_ptr;
   }  // end if
}  // end destroyTree

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Preorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != nullptr)
   {
	  ItemType theItem = node_ptr->GetItem();
	  visit(theItem);
	  Preorder(visit, node_ptr->GetLeftPtr());
	  Preorder(visit, node_ptr->GetRightPtr());
   }  // end if
}  // end preorder

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Inorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != nullptr)
   {
	  Inorder(visit, node_ptr->GetLeftPtr());
	  ItemType theItem = node_ptr->GetItem();
	  visit(theItem);
	  Inorder(visit, node_ptr->GetRightPtr());
   }  // end if
}  // end inorder

template<class ItemType, class OtherType>
void BinarySearchTree<ItemType, OtherType>::Postorder(void visit(ItemType&), BinaryNode<ItemType, OtherType>* node_ptr) const
{
   if (node_ptr != nullptr)
   {
	  Postorder(visit, node_ptr->GetLeftPtr());
	  Postorder(visit, node_ptr->GetRightPtr());
	  ItemType theItem = node_ptr->GetItem();
	  visit(theItem);
   } // end if
}  // end postorder








