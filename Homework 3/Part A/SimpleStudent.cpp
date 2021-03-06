/*SimpleStudent.cpp for Part A
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/

#include "SimpleStudent.h"
#include <iostream>
#include <string>
using namespace std;

/*
*Constructor with default argument
*@param idNo as the id number of the student
*@param stuName as the name of the student
*/
Student::Student(const int idNo, const string stuName)
{
	setName(stuName);
	setId(idNo);
}
/*
* Get id of the student
*@return the id of the student
*/
int Student::getId() const
{
	return id;
}
/*
* Get name of the student
*@return the name of the student
*/
string Student::getName() const
{
	return name;
}
/*
* Set id of the student
*@param idNo as the id number of the student
*/
void Student::setId(const int idNo)
{
	id = idNo;
}
/*
* Set name of the student
*@param stuName as the name of the student
*/
void Student::setName(const string stuName)
{
	name = stuName;
}

