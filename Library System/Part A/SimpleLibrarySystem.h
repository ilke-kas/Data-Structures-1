/*SimpleLibrarySystem.h for Part A
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#ifndef _LIBRARYSYSTEM_H
#define _LIBRARYSYSTEM_H
#include "SimpleStudent.h"
using namespace std;

class LibrarySystem 
{
	public:
		LibrarySystem();
		~LibrarySystem();
		void addStudent(const int studentId, const string studentName);
		void deleteStudent(const int studentId);
		void showStudent(const int studentId) const;
	private:
		struct studentNode
		{
			Student student;
			studentNode* next;
		};
		//data members
		int studentListSize;
		studentNode* studentListHead;
		//helper functions
		studentNode* find(const int index) const;
		bool isStudentListEmpty() const;
		int getStudentListLength() const;
		bool retrieveStudent(const int index, Student& s) const;
		bool insertStudent(const int index,Student newStudent); 
		bool removeStudent(const int index);
		int findStudentIndex(const int id) const;	
};
#endif
