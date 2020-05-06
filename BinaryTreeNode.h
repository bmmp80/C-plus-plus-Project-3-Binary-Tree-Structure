/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/

#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include "Employee.h"

using namespace std;

class BinaryTreeNode
{
public:
	Employee person;
	BinaryTreeNode* parent;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(Employee &newEmployee, BinaryTreeNode * parentptr = NULL, BinaryTreeNode * rightptr = NULL, BinaryTreeNode *leftptr = NULL);
	BinaryTreeNode();


	~BinaryTreeNode();
};
#endif
