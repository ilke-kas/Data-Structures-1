/*Book.cpp for Part B
*Name-Surname: Ilke Kas
*Section: 3
*Student No: 21803184
*/
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;
/*
*Constructor with default argument
*@param BId as the id number of the book
*@param  tit as the title of the book
*@param BYear as the year of the book
*/
Book::Book(const int BId, const string tit, const int BYear)
{
	setId(BId);
	setTitle(tit);
	setYear(BYear);
	setCheckedOut(false);
}

//Get Functions
/*
* Get id of the book
*@return the id of the book
*/
int Book::getId() const
{
	return id;
}
/*
* Get title of the book
*@return the title  of the book
*/
string Book::getTitle() const
{
	return title;
}
/*
* Get year of the book
*@return the year of the book
*/
int Book::getYear() const
{
	return year;
}
/*
* Get checkedout situation of the book
*@return the checkedout or not 
*/
bool Book::getCheckedOut() const
{
	return checkedOut;	
}
//Set functions
/*
* Set id of the book
*@param idNo as the id of the book
*/
void Book::setId(const int idNo)
{
	id = idNo;
}
/*
* Set title of the book
*@param tit as the title of the book
*/
void Book::setTitle(const string tit)
{
	title = tit;
}
/*
* Set year of the book
*@param Byear as the year of the book
*/
void Book::setYear(const int Byear)
{
	year = Byear;
}
/*
* Set availability of the book
*@param checked as avalibity
*/
void Book::setCheckedOut(const bool checked)
{
	checkedOut = checked;
}

