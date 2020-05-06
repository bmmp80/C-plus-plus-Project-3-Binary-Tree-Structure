/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/
#include "BinaryTreeNode.h"
#include <iostream>
#include <cstdlib>
#include "Employee.h"

using namespace std;

	BinaryTreeNode::BinaryTreeNode(Employee& newEmployee, BinaryTreeNode* parentptr, BinaryTreeNode* rightptr, BinaryTreeNode* leftptr)
	{
		person = newEmployee;
		parent = parentptr;
		right = rightptr;
		left = leftptr;
	}

	BinaryTreeNode::BinaryTreeNode()
	{
		parent = nullptr;
		right = nullptr;
		left = nullptr;
	}

	//what will this do?
	BinaryTreeNode::~BinaryTreeNode()
	{

	}

	
