/*LibrarySystem.h for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#ifndef _LIBRARYSYSTEM_H
#define _LIBRARYSYSTEM_H
#include <string>
#include "Student.h"
#include "Book.h"
using namespace std;
class LibrarySystem {
	public:
		LibrarySystem();
		~LibrarySystem();
		void addBook(const int bookId, const string bookName, const int bookYear);//+
		void deleteBook(const int bookId);
		void addStudent(const int studentId, const string studentName);//+
		void deleteStudent(const int studentId);
		void checkoutBook(const int bookId, const int studentId);//+
		void returnBook(const int bookId);//+
		void showAllBooks() const;//+
		void showBook(const int bookId) const;//+
		void showStudent(const int studentId) const;//+
	private:
		//Student Part
		struct studentNode
		{
			Student student;
			studentNode* nextStudent;
		};
		//data members
		int studentListSize;
		studentNode* studentListHead;
		//helper functions
		studentNode* findStudent(const int index) const;
		bool isStudentListEmpty() const;
		int getStudentListLength() const;
		bool retrieveStudent(const int index, Student& s) const;
		bool insertStudent(const int index,Student newStudent); 
		bool removeStudent(const int index);
		int findStudentIndex(const int id) const;
		//Book Part
		struct bookNode
		{
			Book book;
			bookNode* nextBook;
		};
		//data members
		int bookListSize;
		bookNode* bookListHead;
		//helper functions
		bookNode* findBook(const int index) const;
		bool isBookListEmpty() const;
		int getBookListLength() const;
		bool retrieveBook(const int index, Book& b) const;
		bool insertBook(const int index,Book newBook); 
		bool removeBook(const int index);
		int findBookIndex(const int id) const;
		int whoHasTheBook(const int bookId) const;		
		
};
#endif

