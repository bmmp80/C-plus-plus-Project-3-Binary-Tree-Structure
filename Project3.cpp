/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include "Employee.h"
#include "BinarySearchTree.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//file to open: C:\Users\Brandon\Desktop\CS3100\Projects\Project3\Project3\Employee-Database.txt
	int myID = 0;
	Employee* myEmployee = nullptr;
	//Prompts user to choose the number of records to read
	cout << "input queue number of records you would like to read: ";
	int capacity;
	cin >> capacity;
	BinarySearchTree myTree;

	//Prompts user to open a file to use as a database
	string filename;
	cout << "which file do you want to open? ";
	cin >> filename;

	ifstream my_stream;
	my_stream.open(filename);
	if (my_stream.is_open())
	{
		cout << "open file" << endl;
		string line;
		Employee nextEmployee;
		for (int i = 0; i < capacity; i++)
		{
			my_stream >> nextEmployee;
			//cout << nextEmployee;
			myTree.insert(nextEmployee);
			//cout << "after insert function" << endl;
			//myTree.print();
		}

		bool quit = false;
		char option = 'Q';

		//Creating user interface.
		while (!quit)
		{
			cout << "I to insert new record" << endl;
			cout << "D to delete record" << endl;
			cout << "E for employee ID search" << endl;
			cout << "S to save database to file" << endl;
			cout << "Q to quit the program" << endl;
			cin >> option;

			Employee inputEmployee;
			switch (option)
			{
			case 'I':
				//insert		
				//print number of elements
				//print 5 records if stack is > 5
				cout << "Enter an employee record (last name, first name, ID): ";
				cin >> inputEmployee;
				myTree.insert(inputEmployee);
				cout << "tree size: " << myTree.BSTsize() << endl;
				break;

			case 'D':
				//delete
				//Delete Record: Ask the user for an Employee ID and delete it from the Binary Search Tree.
				cout << "Enter an employee ID to delete: " << endl;
				cin >> myID;
				//2 cases: ID is in tree, ID is not in tree
				if (myTree.remove(myID))
				{
					cout << "Delete successful" << endl;
					cout << "tree size: " << myTree.BSTsize() << endl;
				}
				else
				{
					cout << "Error: ID not in tree" << endl;
				}
				break;
			case 'E':
				//employee ID search
				//Search on Employee ID: Print all data to the screen for an Employee whose Employee ID is
				//given via the keyboard.
				cout << "Enter an employee ID to search: " << endl;

				cin >> myID;
				myEmployee = myTree.search(myID);
				//2 cases: ID is in tree, ID is not in tree
				if (myEmployee == nullptr)
				{
					cout << "Error: ID not in tree" << endl;
				}
				else
				{
					cout << *myEmployee << endl;
				}
				break;
			case 'P':
				//print tree
				myTree.print();
				break;
			case 'S':
			{
				//Save: save all the elements in the tree to a file on the disk.
				myTree.save();
			}
			break;
			case 'Q':
			{
				//quit
				quit = true;
				break;
			}

			default:
				cout << "Error: reached default case" << endl;
				break;
			}

		}
		my_stream.close();
	}
	else
	{
		cout << "Error: unable to open file";
	}

	return 0;
}
//work on search function

