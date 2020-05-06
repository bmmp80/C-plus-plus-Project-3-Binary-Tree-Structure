/*
CS3100
Data Structures and Algorithms
Brandon Prenger
prenger.30@wright.edu
Meilin Yiu
07/22/2019
Project 3 (Binary Tree)
*/
#include "Employee.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//creates an employee data structure

//constructor with default member variables
Employee::Employee()
{
	ID = 0;
	lastname = " ";
	firstname = " ";
}

//constructor with parameters
Employee::Employee(int IdNum, std::string last, std::string first)
{
	ID = IdNum;
	lastname = last;
	firstname = first;
}

//copy constructor
Employee::Employee(const Employee& person)
{
	ID = person.ID;
	lastname = person.lastname;
	firstname = person.firstname;
}

//destructor
Employee::~Employee()
{

}

//setter for first name
void Employee::setFirstName(string first)
{
	firstname = first;
}

//setter for last name
void Employee::setLastName(string last)
{
	lastname = last;
}

//setter of ID
void Employee::setID(int IdNum)
{
	ID = IdNum;
}

//getter for ID
int Employee::getID()
{
	return ID;
}

//getter for first name
std::string Employee::getFirstName()
{
	return firstname;
}

//getter for last name
std::string Employee::getLastName()
{
	return lastname;
}

//overriding << operator
std::ostream& operator <<(std::ostream& outs, Employee& person)
{
	outs << person.lastname << " " << person.firstname << " " << person.ID << endl;
	return outs;
}

//overriding >> operator
std::istream& operator >>(std::istream& ins, Employee& person)
{
	ins >> person.lastname >> person.firstname >> person.ID;
	return ins;
}

//print employee information
void Employee::print()
{
	cout << lastname << " " << firstname << " " << ID << endl;
}



