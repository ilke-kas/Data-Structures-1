/*SimpleLibrarySystem.cpp for Part A
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/

#include "SimpleLibrarySystem.h"
#include <iostream>
#include <string>
#include <cstddef> 
using namespace std;    

/*
* Constructor
*/
LibrarySystem::LibrarySystem():
	studentListSize(0),
	studentListHead(NULL)
{
}
/*
*Destructor
*/
LibrarySystem::~LibrarySystem()
{
	while(!isStudentListEmpty())
	{
		removeStudent(1);
	}
}
/*
*This function add student to the library system
*@param studentID
*@param studentName
*/
void LibrarySystem::addStudent(const int studentId, const string studentName)
{
	//check whether or not the specified student id already exists
	if(findStudentIndex(studentId) != -1)
	{
		cout<< "Student "<<studentId<<" already exists."<<endl;
	}
	else
	{
		if(studentId > 0 )
		{
			//create Student with given info
			Student stu(studentId,studentName);
			bool done = insertStudent(studentListSize+1,stu);
			if(done)
			cout<< "Student "<<studentId<<" has been added."<<endl;
		}
	}
	
}
/*This function will traverse the student list to find given id
*@param studentId
*@return index of the student at the list
*/
int LibrarySystem::findStudentIndex(const int studentId) const
{
	int index = 1;
	for(studentNode* cur = studentListHead; cur != NULL; cur = cur->next,index++)
	{
		if((cur->student).getId() == studentId)
			return index;
	}
	return -1;
}
/*This function will delete student whose id is given from LibrarySystem
*@param studentId 
*/
void LibrarySystem::deleteStudent(const int studentId)
{
	//check whether or not the specified student id already exists
	int index = findStudentIndex(studentId);
	if(index == -1)
	{
		cout<<"Student "<<studentId<<" does not exist."<<endl;
	}
	else
	{
		bool done = removeStudent(index);
		if(done)
			cout<<"Student "<<studentId<<" has been deleted"<<endl;
	}	
}
/*
*
*/	
void LibrarySystem::showStudent(const int studentId) const
{
	int index = findStudentIndex(studentId);
	if(index == -1)
	{
		cout<<"Student "<<studentId<<" does not exist."<<endl;
	}
	else
	{
		Student s;
		retrieveStudent(index,s);
		cout<<"Student id: "<< s.getId() <<" student name: "<<s.getName()<<endl;	
	}		
}

//	Functions for Linked List
/*
* This function returns true if the student List is empty
*@return bool 
*/
bool LibrarySystem::isStudentListEmpty() const
{
	return studentListSize == 0;
}
/*
* This function returns the size of the studen list
*@return length of the student list
*/
int LibrarySystem::getStudentListLength() const
{
	return studentListSize;
}
/*
*This function find the node's address with given index
*@param index 
*/
LibrarySystem::studentNode* LibrarySystem::find(const int index) const
{
	if((index < 1 ) || (index > getStudentListLength() ))
		return NULL;
	else
	{
		studentNode* current = studentListHead;
		for(int i = 1 ; i < index; i++)
			current = current-> next;
		return current;
	}
}

/*
*This function get the Student in the given index
*@param index
*@param stu as the student
*/
bool LibrarySystem::retrieveStudent(const int index, Student& stu) const
{
	if((index <1) || (index > getStudentListLength()))
		return false;
	studentNode* current = find(index);
	stu = current-> student;
	return true;
}
/*
*This function will insert student at the given index 
*@param index
*@param newStudent
*/
bool LibrarySystem::insertStudent(const int index,Student newStudent)
{
	if((index <1) || (index > (studentListSize + 1 )))
		return false;
	studentNode* newStu = new studentNode;
	studentListSize = getStudentListLength() + 1;
	newStu->student = newStudent;
	
	if(index == 1)
	{
		newStu-> next = studentListHead;
		studentListHead = newStu; 
	}
	else
	{
		studentNode* prev = find(index-1);
		newStu -> next = prev ->next;
		prev->next = newStu;
	}
	return true;
}
/*
*This function  will remove student at given index
*@param index
*/
bool LibrarySystem::removeStudent(const int index)
{
	studentNode* current;
	if((index <1) || (index > getStudentListLength()))
		return false;
	studentListSize--;
	if(index==1)
	{
		current = studentListHead;
		studentListHead = studentListHead-> next;
	}
	else
	{
		studentNode* prev = find(index-1);
		current = prev->next;
		prev->next = current->next;
	}
	current->next = NULL;
	delete current;
	current = NULL;
	
	return true;
}


