/*Student.cpp for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#include "Student.h"
#include <iostream>
#include <string>
#include <cstddef>     
#include <iomanip>
using namespace std;

/*
*Constructor with default argument
*@param idNo as the id number of the student
*@param stuName as the name of the student
*/
Student::Student(const int idNo, const string stuName):
	bookListSize(0),
	bookListHead(NULL)
{
	setName(stuName);
	setId(idNo);
}
/*
*Destructor
*/
Student::~Student()
{
	while(!isStudentBookListEmpty())
		removeBookFromStudent(1);
}
/*
*Copy Constructor
*/
Student::Student(const Student& stu):
	id(stu.id),
	name(stu.name),
	bookListSize(stu.bookListSize)
	{
		if(stu.bookListHead== NULL)
			bookListHead = NULL;
		else
		{
			//copy the first node
			bookListHead = new StudentBookNode;
			bookListHead->book = stu.bookListHead->book;
			//copy the rest
			StudentBookNode* newBo = bookListHead;
			for(StudentBookNode* stuPtr = stu.bookListHead; stuPtr != NULL; stuPtr = stuPtr->next )
			{
				newBo->next = new StudentBookNode;
				newBo = newBo->next;
				newBo->book = stuPtr->book;
			}
			newBo->next = NULL;
		}	
	}
//List operations
/*
* This function returns true if the book List of the student is empty
*@return bool 
*/
bool Student::isStudentBookListEmpty() const
{
	return bookListSize == 0;
}
/*
* This function returns the size of the book list of the student
*@return length of the book list of the student
*/
int Student::getStudentBookLength() const
{
	return bookListSize;
}
/*
*This function find the node's address with given index
*@param index 
*/
Student::StudentBookNode* Student::find(const int index) const
{
	
	if( (index<1)|| (index > getStudentBookLength()))
		return NULL;
	else
	{
		StudentBookNode* current = bookListHead;
		for(int i = 1; i <index; i++)
			current = current->next;
		return current;
	}
}
/*
*This function get the Book in the given index
*@param index
*@param book
*/
bool Student::retrieveBookFromStudent(const int index, Book& book) const
{
	if( (index<1)|| (index > getStudentBookLength()))
		return false;
	StudentBookNode* current = find(index);
	book = current->book;
	return true;
}
/*
*This function will insert book  to the student's book list at given index
*@param index
*@param newBook
*/
bool Student::insertBookToStudent(const int index,const Book newBook)
{
	if( (index<1)|| (index > (getStudentBookLength()+1)))
		return false;
	StudentBookNode* newBo = new StudentBookNode;
	bookListSize++;
	newBo->book = newBook;
	
	if(index == 1)
	{
		newBo->next = bookListHead;
		bookListHead = newBo;
	}
	else
	{
		StudentBookNode* previous = find(index-1);
		newBo->next = previous->next;
		previous->next = newBo;
	}
	return true;
}
/*
*This function  will remove book at given index
*@param index
*/
bool Student::removeBookFromStudent(const int index)
{
	StudentBookNode* current;
	if( (index<1)|| (index > getStudentBookLength()))
		return false;
	--bookListSize;
	if(index == 1)
	{
		current = bookListHead;
		bookListHead = bookListHead->next;
	}
	else
	{
		StudentBookNode* previous = find(index-1);
		current = previous->next;
		previous->next = current->next;
	}	
	//delete current for memleak
	current->next = NULL; // not to point our list
	delete current;
	current = NULL;
	return true;
}
/*This function will traverse the book list to find given id
*@param bookId
*@return index of the book at the list
*/
int Student::findBookIndex(const int bookId) const
{
	int index = 1;
	for(StudentBookNode* cur = bookListHead; cur != NULL; cur = cur->next,index++)
	{
		if((cur->book).getId() == bookId)
			return index;
	}
	return -1;
}
/*This function will display all books of the student
*/
void Student::displayAllBooks() const
{
	cout<<setw(10)<<left<<"Book id"<<setw(25)<<left<<"Book Name"<<setw(15)<<left<<"Year"<<endl;
	for(StudentBookNode* cur = bookListHead; cur != NULL; cur = cur->next)
	{
		cout<<setw(10)<<left<<(cur->book).getId()<<setw(25)<<left<<(cur->book).getTitle()<<setw(15)<<left<<(cur->book).getYear()<<endl;
	}
}
/*This function will display all books of the student
*/
void Student::displayAllBooksWithStatus() const
{
	for(StudentBookNode* cur = bookListHead; cur != NULL; cur = cur->next)
	{
		cout<<setw(10)<<left<<(cur->book).getId()<<setw(25)<<left<<(cur->book).getTitle()<<setw(15)<<left<<(cur->book).getYear()
		<<setw(15)<<left<<"Checked out by student "<<id<<endl;
	}
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

