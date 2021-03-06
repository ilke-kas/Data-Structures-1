/*LibrarySystem.cpp for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#include "LibrarySystem.h"
#include <iostream>
#include <string>
#include <cstddef> 
#include <iomanip>
using namespace std;    

/*
* Constructor
*/
LibrarySystem::LibrarySystem():
	studentListSize(0),
	studentListHead(NULL),
	bookListSize(0),
	bookListHead(NULL)
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
	while(!isBookListEmpty())
	{
		removeBook(1);
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
		if(studentId > 0)//student ids must be unique positive integers
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
	for(studentNode* cur = studentListHead; cur != NULL; cur = cur->nextStudent,index++)
	{
		if((cur->student).getId() == studentId)
			return index;
	}
	return -1;
}
/*
*This function add book to the library system
*@param bookId
*@param bookName
*@param bookYear
*/
void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear)
{
	//check whether or not the specified book id already exists
	if(findBookIndex(bookId) != -1 || whoHasTheBook(bookId) != -1 )
	{
		cout<< "Book "<<bookId<<" already exists."<<endl;
	}
	else
	{
		if(bookId > 0)//book ids must be unique positive integers
		{
			//create Book with given info
			Book B(bookId,bookName,bookYear);
			bool done = insertBook(bookListSize+1,B);
			if(done)
			cout<< "Book "<<bookId<<" has been added."<<endl;
		}
	}
}
/*This function will traverse the book list to find given id
*@param bookId
*@return index of the book at the list
*/
int LibrarySystem::findBookIndex(const int bookId) const
{
	int index = 1;
	for(bookNode* cur = bookListHead; cur != NULL; cur = cur->nextBook,index++)
	{
		if((cur->book).getId() == bookId)
			return index;
	}
	return -1;
}
/*This function enable students to checked out book with given id if it is available 
*@param bookId
*@param studentId
*/
void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
	int indexBook = findBookIndex(bookId);
	int indexStudent = findStudentIndex(studentId);
	studentNode* stuPtr = findStudent(indexStudent);
	bookNode* bookPtr = findBook(indexBook);
	//check whether or not this book exists
	if(indexBook == -1)
	 	cout<<"Book "<< bookId<< " does not exist for checkout"<<endl;
	else if(indexStudent == -1)
		cout<<"Student "<<studentId<<" does not exist for check out"<<endl;
	else
	{
		//check whether book is taken by other student or not
		if((bookPtr->book).getCheckedOut())
			cout<<"Book "<<bookId<<" has been already checked out by another student."<<endl;
		else
		{
			//checked out book
			//change the availability of the book
			(bookPtr->book).setCheckedOut(true);
			// add that book to the student's book list
			(stuPtr->student).insertBookToStudent(((stuPtr->student).getStudentBookLength()) + 1, bookPtr-> book );
			//remove book from the library system's not checkedout books
			removeBook(indexBook);
			cout<<"Book "<<bookId<<" has been  checked out by student "<<studentId<<endl;
		}
	}	
}
/*This function will display detailed information about that particular book
*If the book is checked out, id and name of the student who checked out the book should be displayed
*@param bookId
*/
void LibrarySystem::showBook(const int bookId) const
{	
	//find the student who have that book
	int stuIndex = whoHasTheBook(bookId);
	studentNode* stuPtr = findStudent(stuIndex);
	//find the book
	int bookIndex = findBookIndex(bookId);
	bookNode* bookPtr = findBook(bookIndex);
	//display results
	if(whoHasTheBook(bookId) == -1 )
		cout<<setw(10)<<left<<bookId<<setw(25)<<left<<(bookPtr->book).getTitle()<<setw(15)<<left
		<<(bookPtr->book).getYear()<<setw(15)<<"Not checked out"<<endl;
	else 
	{
		int bookInStudent = (stuPtr->student).findBookIndex(bookId);
		Book B;
		(stuPtr->student).retrieveBookFromStudent(bookInStudent, B);
		cout<<setw(10)<<left<<bookId<<setw(25)<<left<<B.getTitle()<<setw(15)<<left
		<<B.getYear()<<setw(15)<< "Checked out by student "<< (stuPtr->student).getId()<<endl;
	}
}
/*This function will find the student index which checked out the given book
*@param bookId
*@return the index of the student
*/
int LibrarySystem::whoHasTheBook(const int bookId) const
{
	//traverse the student List
	int index = 1;
	for(studentNode* cur = studentListHead; cur != NULL; cur = cur->nextStudent,index++)
	{
		if((cur->student).findBookIndex(bookId) != -1 )
			return index;
	}
	return -1;
}

/*This function will display the list of all the books in Library system
*For each book that is
*checked out, id and name of the student who checked out the book should also be displayed.
*/
void LibrarySystem::showAllBooks() const
{
	//show all books that are not checked
	cout<<setw(10)<<left<<"Book id"<<setw(25)<<left<<"Book Name"<<setw(15)<<left<<"Year"<<setw(15)<<"Status"<<endl;
	//traverse the book list and display each of the book
	for(bookNode* cur = bookListHead; cur != NULL; cur = cur->nextBook)
	{
		showBook((cur->book).getId());
	}
	//show all books that are checked by students
	//traverse the student list and display each of their books
	for(studentNode* cur = studentListHead; cur != NULL; cur = cur->nextStudent)
	{
		(cur->student).displayAllBooksWithStatus();
	}
	
}
/*This funcyion will Show detailed information about a particular student
*@param studentId
*/
void LibrarySystem::showStudent(const int studentId) const
{
	int index = findStudentIndex(studentId);
	studentNode* stuPtr = findStudent(index);
	if(index == -1)
		cout<<"Student "<< studentId <<" does not exist"<<endl;
	else
	{
		cout<<"Student id: "<< studentId << " student name: "<< (stuPtr->student).getName()<<endl;
		if((stuPtr->student).isStudentBookListEmpty())
			cout<<"Student "<<studentId<< " has no books"<<endl;
		else
		{
			cout<<"Student "<<studentId<<" has checked out the following books:"<<endl;
			(stuPtr->student).displayAllBooks();
		}
	}	
}
/*This function will allow to student to return his/her books to the library system
*@param bookId
*/
void LibrarySystem::returnBook(const int bookId)
{
	int index = findBookIndex(bookId);
	int personHasBook = whoHasTheBook(bookId);
	bookNode* bookPtr = findBook(index);
	if((index == -1 )&& (personHasBook == -1 ))
		cout<<"Book "<< bookId<<" does not exist"<<endl;
	else if( personHasBook == -1 )
		cout<<"Book "<< bookId<<" has not been checked out"<<endl;
	else
	{
		//find the person
		//return the book
		//remove it from the students list
		//first find who has this book
		int studentIndex = whoHasTheBook(bookId);
		studentNode* stuPtr = findStudent(studentIndex);
		//remove it from student's book list
		int bookIndex = (stuPtr->student).findBookIndex(bookId);
		Book B;
		(stuPtr->student).retrieveBookFromStudent(bookIndex,B);
		string bookName = B.getTitle();
		int bookYear = B.getYear();
	    (stuPtr->student).removeBookFromStudent(bookIndex);
	   	//add it to the library's unchecked out list 
		//add book to unchecked list
		//check whether or not the specified book id already exists
		if(findBookIndex(bookId) != -1 || whoHasTheBook(bookId) != -1 ){
		}
		else
		{
			if(bookId > 0)//book ids must be unique positive integers
			{
				//create Book with given info
				Book B(bookId,bookName,bookYear);
				bool done = insertBook(bookListSize+1,B);
			}
		}
		cout<<"Book "<< bookId<<" has been returned"<<endl;
	}	
}
/*
*This function will delete students and return all of his/her books
*@param studentId
*/
void LibrarySystem::deleteStudent(const int studentId)
{
	int studentIndex = findStudentIndex(studentId);
	studentNode* stuPtr = findStudent(studentIndex);
	if(studentIndex == -1)
		cout<<"Student "<<studentId<<" does not exist"<<endl;
	else
	{
		Book B;
		int max = ((stuPtr->student).getStudentBookLength());
		//first return all of the books that is checked 
		for(int index = 1 ; index <= max; index++)
		{
			(stuPtr->student).retrieveBookFromStudent(1,B);
			returnBook(B.getId()); 
		}
		//delete student from student list
		removeStudent(studentIndex);
		cout<<"Student "<< studentId<< " has been deleted"<<endl;
	}
}
/**This function will  allow to delete an existing book specified with its book id
*@param bookId
*/
void LibrarySystem::deleteBook(const int bookId)
{
	int index = findBookIndex(bookId);
	int personHasBook = whoHasTheBook(bookId);
	if(index == -1 && personHasBook == -1)
		cout<<"Book "<<bookId<<" does not exist"<<endl;
	else
	{
		if(personHasBook != -1)
		{
			returnBook(bookId);//first return them
		}
		else
		{
			cout<<"Book "<< bookId<<" has not been checked out"<<endl;
		}
		//then remove them from the book list
		int newindex = findBookIndex(bookId);
		removeBook(newindex);
		cout<<"Book "<< bookId<< " has been deleted"<<endl;
	}
}
//	Functions for Linked List for Student
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
LibrarySystem::studentNode* LibrarySystem::findStudent(const int index) const
{
	if((index < 1 ) || (index > getStudentListLength() ))
		return NULL;
	else
	{
		studentNode* current = studentListHead;
		for(int i = 1 ; i < index; i++)
			current = current-> nextStudent;
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
	studentNode* current = findStudent(index);
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
		newStu-> nextStudent = studentListHead;
		studentListHead = newStu; 
	}
	else
	{
		studentNode* prev = findStudent(index-1);
		newStu -> nextStudent = prev ->nextStudent;
		prev->nextStudent = newStu;
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
		studentListHead = studentListHead-> nextStudent;
	}
	else
	{
		studentNode* prev = findStudent(index-1);
		current = prev->nextStudent;
		prev->nextStudent = current->nextStudent;
	}
	current->nextStudent = NULL;
	delete current;
	current = NULL;
	
	return true;
}
//	Functions for Linked List for Book
/*
* This function returns true if the book List is empty
*@return bool 
*/
bool LibrarySystem::isBookListEmpty() const
{
	return bookListSize == 0;
}
/*
* This function returns the size of the book list
*@return length of the book list
*/
int LibrarySystem::getBookListLength() const
{
	return bookListSize;
}
/*
*This function find the node's address with given index
*@param index 
*/
LibrarySystem::bookNode* LibrarySystem::findBook(const int index) const
{
	if((index < 1 ) || (index > getBookListLength() ))
		return NULL;
	else
	{
		bookNode* current = bookListHead;
		for(int i = 1 ; i < index; i++)
			current = current-> nextBook;
		return current;
	}
}
/*
*This function get the Book in the given index
*@param index
*@param bo as the book
*/
bool LibrarySystem::retrieveBook(const int index, Book& bo) const
{
	if((index <1) || (index > getBookListLength()))
		return false;
	bookNode* current = findBook(index);
	bo = current-> book;
	return true;
}
/*
*This function will insert book at the given index 
*@param index
*@param newBook
*/
bool LibrarySystem::insertBook(const int index,Book newBook)
{
	if((index <1) || (index > (bookListSize + 1 )))
		return false;
	bookNode* newBo = new bookNode;
	bookListSize = getBookListLength() + 1;
	newBo->book = newBook;
	
	if(index == 1)
	{
		newBo-> nextBook = bookListHead;
		bookListHead = newBo; 
	}
	else
	{
		bookNode* prev = findBook(index-1);
		newBo -> nextBook = prev ->nextBook;
		prev->nextBook = newBo;
	}
	return true;
}
/*
*This function  will remove book at given index
*@param index
*/
bool LibrarySystem::removeBook(const int index)
{
	bookNode* current;
	if((index <1) || (index > getBookListLength()))
		return false;
	bookListSize--;
	if(index==1)
	{
		current = bookListHead;
		bookListHead = bookListHead-> nextBook;
	}
	else
	{
		bookNode* prev = findBook(index-1);
		current = prev->nextBook;
		prev->nextBook = current->nextBook;
	}
	current->nextBook = NULL;
	delete current;
	current = NULL;
	
	return true;
}




