//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinarySearchTree.h"  // ADT binary tree operations
#include "LinkedList.h" // ADT list operations
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Used to 
string normalize(string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		// If any char is not in ASCII, then this is an invalid word
		if (input[i] < 0 || input[i] > 255)
		{
			return "";
		}

		// If any char is a number, then this is an invalid word
		if (isdigit(input[i]))
		{
			return "";
		}

		// Make all alpha chars lower
		if (isalpha(input[i]))
		{
			input[i] = tolower(input[i]);
		}
		
		// Remove all punctuation from the string
		if (ispunct(input[i]) || isspace(input[i]))
		{
			input.erase(i, 1);
			i--;
		}
	}

	return input;
}

int main()
{
	/*
  BinarySearchTree<string, int>* tree1Ptr = new BinarySearchTree<string, int>();
   
  tree1Ptr->Add("70", 100);
  tree1Ptr->Add("50", 2);
  tree1Ptr->Add("40", 1);
  tree1Ptr->Add("10", 10);
  tree1Ptr->Add("20", 1);
  tree1Ptr->Add("30", 1);
  tree1Ptr->Add("60", 1);
  tree1Ptr->Add("80", 1);
   
   cout << "Tree 1 Preorder: \n";
   tree1Ptr->PreorderTraverse(display);
   
   cout << "Tree 1 Inorder: \n";
   tree1Ptr->InorderTraverse(display);
   
   cout << "Tree 1 Postorder: \n";
   tree1Ptr->PostorderTraverse(display);
   
   cout << "Tree 1 height: " << tree1Ptr->GetHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1Ptr->GetNumberOfNodes() << endl;
   
   */

   
   BinarySearchTree<string, LinkedList<int> > myIndex;
   ifstream input_file("document1.txt");
   string line, word;

   // The following is the solution to Part (a)
   if (input_file.is_open())
   {
	   unsigned int counter = 0;
	   while (input_file.good())
	   {
		   // Pull a line from the input file (new line delimiter)
		   getline(input_file, line);
		   stringstream strstr(line);
		   LinkedList<int> line_num_list;
		   line_num_list.Insert(1, counter);

		   while (strstr.good())
		   {
			   // Pull a word from the line (new line and space delimiter)
			   getline(strstr, word, ' ');

			   // normalize(word)
			   // (1) Void words with non-ASCII characters
			   // (2) Void words with numerals
			   // (3) Force all characters to lower case
			   // (4) Delete all punctuation from the word (shrinks str.len)

			   word = normalize(word);
			   
			   if (word.length() > 0)
			   {
				   // Add() will not allow for duplicate words
				   myIndex.Add(word, line_num_list);
			   }
		   }
		   counter++;
	   }
	   input_file.close();
   }
   else
   {
	   cout << "Can't open file" << endl;
   } // End Part (a)
   

   // The following is the solution to Part (b)
   // Inorder Traversal of the tree with word frequency and line of occurrence
   myIndex.printFullIndex();
   cout << "\n\n";
	// End Part (b)


   // The following is the solution to Part (c)
   cout << "The number of nodes in myIndex is: " << myIndex.GetNumberOfNodes() << "\n\n";
	// End Part (c)


   // The following is the solution to Part (d)
   cout << "The height of myIndex is: " << myIndex.GetHeight() << "\n\n";
	// End Part (d)

   
   // The following is the solution to Part (e)
   BinaryNode<string, LinkedList<int> >* most_freq = myIndex.findMostFrequent();
   string freq_word = most_freq->GetItem();
   int frequency = most_freq->GetOther().GetLength();

   cout << "The most frequent word is: \"" << freq_word;
   cout << "\" Count: " << frequency << " Lines: ";
   for (int i = 1; i <= frequency; i++)
   {
	   cout << most_freq->GetOther().GetEntry(i) << ", ";
   }
   cout << "\n\n";
   // End Part (e)


   // The following is the solution to Part (f)
   string user_word;
   cout << "Find a word: ";
   cin >> user_word;
   user_word = normalize(user_word);
   
   if (myIndex.Contains(user_word))
   {
	   BinaryNode<string, LinkedList<int> >* found_word = myIndex.findItem(user_word);
	   cout << "The word is: \"" << user_word;
	   cout << "\" Count: " << found_word->GetOther().GetLength() << " Lines: ";
	   for (int i = 1; i <= found_word->GetOther().GetLength(); i++)
	   {
		   cout << found_word->GetOther().GetEntry(i) << ", ";
	   }
	   cout << "\n\n";
   }
   else
   {
	   cout << "Word not found" << "\n\n";
   }
   // End Part (f)

   // Part (g)
   cout << "Remove a word: ";
   cin >> user_word;
   user_word = normalize(user_word);

   if (myIndex.Contains(user_word))
   {
	   cout << "before remove, contains word? " << myIndex.Contains(user_word) << endl;
	   myIndex.Remove(user_word);
	   cout << "after remove, contains word? " << myIndex.Contains(user_word) << endl;
   }
   else
   {
	   cout << "Word not found" << "\n\n";
   }
   // End Part (g)

   return 0;
}  // end main
