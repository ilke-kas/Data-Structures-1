#include <iostream>
#include <string>
#include "City.h"
using namespace std;
/*
*Constructor
*/
City::City(const string cname, const bool mark)
{
	setName(cname);
	setMarked(mark);
}
//Set Functions
void City::setName(const string cname)
{
	name = cname;
}
void City::setMarked( const bool mark)
{
	marked = mark;
}
//get functions
string City::getName() const
{
	return name;
}
bool City::getMarked() const
 {
 	return marked;
 }


