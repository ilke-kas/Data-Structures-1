/*SimpleStudent.h for Part A
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#include <string>
#ifndef _STUDENT_H
#define _STUDENT_H
using namespace std;

class Student{
	public:
		Student( const int = 0, const string = ""); // constructor with a default argument
		//get Fubctions
		int getId() const;
		string getName() const;
		//Set functions
		void setId(const int id);
		void setName(const string name);
	private:
		int id;
		string name;
};

#endif
