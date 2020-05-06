/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/
#include "BinarySearchTree.h" 
#include <cstdlib>
#include "BinaryTreeNode.h"
#include "Employee.h"
#include <iostream>
#include <fstream>

using namespace std;


	BinarySearchTree::BinarySearchTree()	//constructor
	{
		size = 0;
		root = nullptr;
	}
	
	//destructor
	BinarySearchTree::~BinarySearchTree()
	{
		
	}
		
	bool BinarySearchTree::clear()
	{
		//traverse through tree, delete each node (use post order: left, right, root)
		return true;
	}

	bool BinarySearchTree::insert(Employee& emp)
	{
		// Create a new Node containing 
		// the new element 
		BinaryTreeNode* newNode = new BinaryTreeNode(emp, nullptr, nullptr, nullptr);

		// Pointer to start traversing from root and 
		// traverses downward path to search 
		// where the new node to be inserted 
		BinaryTreeNode* x = root;

		// Pointer y maintains the trailing 
		// pointer of x 
		BinaryTreeNode* y = nullptr;

		while (x != nullptr) 
		{
			y = x;
			Employee nextEmployee = x->person;
			if (emp.getID() < nextEmployee.getID())
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		// If the root is NULL i.e the tree is empty 
		// The new node is the root node 
		if (y == nullptr)
		{
			root = newNode;
		}
		// If the new key is less then the leaf node key 
		// Assign the new node to be its left child 
		else if (emp.getID() < y->person.getID())
		{
			y->left = newNode;
		}

		// else assign the new node its right child 
		else
			y->right = newNode;

		size++;
		// Returns the pointer where the 
		// new node is inserted 
		return true;
	}

	Employee* BinarySearchTree::search(int k)
	{
		BinaryTreeNode* x = root;

		// Pointer y maintains the trailing
		while ((x != nullptr) && (x->person.getID() != k))
		{
			Employee nextEmployee = x->person;
			if (k < nextEmployee.getID())
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		if (x == nullptr)
		{
			return nullptr;
		}
		else
		{
			return &x->person;
		}
	}

	bool BinarySearchTree::remove(int k)
	{
		if (root == nullptr) 
		{
			cout << "There are no nodes in this Binary Search Tree";
			return false;
		}
		else 
		{
			BinaryTreeNode* currentNode = root;
			BinaryTreeNode* parentNode = nullptr;

			while (true) 
			{
				if (k > currentNode->person.getID()) 
				{
					if (currentNode->right != nullptr) 
					{
						parentNode = currentNode;
						currentNode = currentNode->right;
					}
					else 
					{
						return false;
					}
				}
				else if (k < currentNode->person.getID()) 
				{
					if (currentNode->left != nullptr) {

						parentNode = currentNode;
						currentNode = currentNode->left;
					}
					else 
					{
						return false;
					}
				}
				else 
				{
					//no children
					if ((currentNode->left == nullptr) && (currentNode->right == nullptr)) 
					{
						//tree is only root
						if (parentNode == nullptr) 
						{
							delete root;
							root = nullptr;
							size--;
							return true;
						}
						//if parent exists and has a left child
						else if ((parentNode->left != nullptr) && (parentNode->left->person.getID() == currentNode->person.getID())) 
						{
							delete currentNode;
							parentNode->left = nullptr;
							size--;
							return true;
						}
						//parent exists and has right child
						else 
						{
							delete currentNode;
							parentNode->right = nullptr;
							size--;
							return true;
						}
					}
					//current node has only right child
					else if (currentNode->left == nullptr) 
					{
						if (parentNode == nullptr) 
						{
							root = currentNode->right;
							delete currentNode;
							size--;
							return true;
						}
						//deleting left child of parent
						else if ((parentNode->left != nullptr) && (parentNode->left->person.getID() == currentNode->person.getID()))
						{
							parentNode->left = currentNode -> right;
							delete currentNode;
							size--;
							return true;
						}
						//deleting right child of parent
						else 
						{
							parentNode->right = currentNode -> right;
							delete currentNode;
							size--;
							return true;
						}
					}
					//current node has only left child
					else if (currentNode->right == nullptr) 
					{
						//deleting root
						if (parentNode == nullptr) 
						{
							root = currentNode->left;
							delete currentNode;
							size--;
							return true;
						}
						//parent has a left child and key matches
						else if ((parentNode->left != nullptr) && (parentNode->left->person.getID() == currentNode->person.getID()))
						{
							parentNode->left = currentNode->left;
							delete currentNode;
							size--;
							return true;
						}
						//parent has a right node
						else 
						{
							parentNode->right = currentNode->left;
							delete currentNode;
							size--;
							return true;
						}
					}
					//current node has two children
					else 
					{
						int successorNodeValue = getSuccessorNodeValue(currentNode->right);
						remove(successorNodeValue);
						currentNode->person.setID(successorNodeValue);
						size--;
						return true;
					}
				}
			}
		}
	}

	int BinarySearchTree::getSuccessorNodeValue(BinaryTreeNode* currentNode) 
	{
		while (true) 
		{
			if (currentNode->left != nullptr) 
			{
				currentNode = currentNode->left;
			}
			else 
			{
				break;
			}
		}
		return currentNode->person.getID();
	}

	int BinarySearchTree::BSTsize()
	{
		return size;
	}
	bool BinarySearchTree::save()
	{
		cout << "Enter output file name: ";
		string fileName;
		cin >> fileName;
		ofstream outfile(fileName);
		print(root, outfile);
		outfile.close();
		return true;
	}
	void BinarySearchTree::print()
	{
		print(root, cout);
	}

	void BinarySearchTree::print(BinaryTreeNode* node, ostream& os)
	{
		//print left subtree, print right subtree, print root
		if (node->left != nullptr)
		{
			print(node->left, os);
		}
		Employee myEmployee = node->person;
		os << myEmployee;
		if (node->right != nullptr)
		{
			print(node->right, os);
		}
	}
	//copy main program from project 2
	//has program that reads from file and menu structure
	//just have to change stack to tree
	//read record, insert to tree, print the tree



	//ask if clear is the same as destructor


