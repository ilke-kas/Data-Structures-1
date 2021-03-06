/*Student.h for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
#include "Book.h"
using namespace std;

class Student{
	public:
		Student( const int = 0, const string = ""); // constructor with a default argument
		Student(const Student& stu); //copy constructor
		~Student(); //destructor
		//get Functions
		int getId() const;
		string getName() const;
		//Set functions
		void setId(const int id);
		void setName(const string name);
		//list operations
		bool isStudentBookListEmpty() const;
		int getStudentBookLength() const;
		bool retrieveBookFromStudent(const int index, Book& book) const;
		bool insertBookToStudent(const int index,const Book newBook);
		bool removeBookFromStudent(const int index);
		int findBookIndex(const int id) const;
		void displayAllBooks() const;
		void displayAllBooksWithStatus() const;
		
	private:
		struct StudentBookNode{
			Book book;
			StudentBookNode* next;
		};
		int bookListSize;
		StudentBookNode* bookListHead;
		int id;
		string name;
		//Helper functions
		StudentBookNode *find(int index) const;
};
#endif


