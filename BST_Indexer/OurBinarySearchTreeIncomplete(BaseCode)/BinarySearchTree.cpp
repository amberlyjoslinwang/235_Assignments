//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

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
    cout << "Incomplete Assignment Operator " << endl;
  // COMPLETE ASSIGNMENT OPERATOR
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

template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Remove(const ItemType& target)
{
  cout << "Incomplete Remove " << endl;
  return false;
}  // end remove

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
  cout << "Incomplete Contains" << endl;
  return false;
}  // end contains


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
  cout << "Incomplete GetNumberOfNodesHelper" << endl;
  return -1;
}  // end GetNumberOfNodesHelper


template<class ItemType, class OtherType>
bool BinarySearchTree<ItemType, OtherType>::Add(const ItemType& new_item, const OtherType& new_other)
{
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
  cout << "Incomplete InsertInorder" << endl;
  return nullptr;
}  // end insertInorder

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveValue(BinaryNode<ItemType, OtherType>* subTreePtr,
										    const ItemType target, 
										    bool& success)
{
  cout << "Incomplete RemoveValue" << endl;
  success = false;
  return nullptr;
}  // end RemoveValue

template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveNode(BinaryNode<ItemType, OtherType>* nodePtr)
{
  cout << "Incomplete Remove Node" << endl;
  return nullptr;
}  // end RemoveNode

template<class ItemType, class OtherType> 
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::RemoveLeftmostNode(BinaryNode<ItemType, OtherType>* nodePtr,
                                                                     ItemType& inorderSuccessor)
{
  cout << "Incomplete RemoveLeftmostNode" << endl;
  return nullptr;
}  // end RemoveLeftmostNode


template<class ItemType, class OtherType>
BinaryNode<ItemType, OtherType>* BinarySearchTree<ItemType, OtherType>::FindNode(BinaryNode<ItemType, OtherType>* subTreePtr,
                                                           const ItemType& target) const 
{
  cout << "Incomplete FindNode" << endl;
  return nullptr;
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








