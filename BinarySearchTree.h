/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/
#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include <cstdlib>
#include "BinaryTreeNode.h"
#include "Employee.h"
#include <ostream>

using namespace std;

class BinarySearchTree {
	public:
		BinarySearchTree();	//constructor
		~BinarySearchTree();	//destructor
		bool clear();
		bool insert(Employee & emp);
		Employee* search(int k);
		bool remove(int k);
		int BSTsize();
		bool save();
		void print();
		//ask if delete is same as remove
	private:
		void print(BinaryTreeNode* node, ostream& os);
		BinaryTreeNode * root;
		int size;
		int getSuccessorNodeValue(BinaryTreeNode* currentNode);

};


#endif
 
