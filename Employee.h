/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/

#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Employee
{

public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void print();
	void setFirstName(string first);
	void setLastName(string last);
	void setID(int IdNum);
	int getID();
	std::string getFirstName();
	std::string getLastName();
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;
};


#endif