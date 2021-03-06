/*Book.h for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#ifndef _BOOK_H
#define _BOOK_H
#include <string>
using namespace std;

class Book{
	public:
		Book(const int id = 0, const string title ="", const int year = 0); //constructor with default argument
		//get functions
		int getId() const;
		int getYear() const;
		string getTitle() const;
		bool getCheckedOut() const;
		//set functions
		void setId(const int id);
		void setYear(const int);
		void setTitle(const string);
		void setCheckedOut(const bool checked);
	private:
		int id;
		string title;
		int year;	
		bool checkedOut;
};
#endif
