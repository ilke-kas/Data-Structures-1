//Flight.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "Flight.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight(const int Id, const int fcost,const string dept, const string dest)
{
	setId(Id);
	setCost(fcost);
	setDept(dept,false);
	setDest(dest,false);
	setMarked(false);
}
//Set functions
void Flight::setCost(const int fcost)
{
	cost =fcost;
}
void Flight::setId(const int Id)
{
	id = Id;
}
void Flight::setMarked(const bool mark)
{
	marked = mark;
}
void Flight::setDest(const string dept, const bool mark)
{
	destCity.setName(dept);
	destCity.setMarked(mark);
}
void Flight::setDept(const string dept, const bool mark)
{
	deptCity.setName(dept);
	deptCity.setMarked(mark);
}
//Get functions
int Flight::getCost() const
{
	return cost;
}
int Flight::getId() const
{
	return id;
}
City Flight::getDest() const
{
	return destCity;
}
City Flight::getDept() const
{
	return deptCity;
}
bool Flight::getMarked() const
{
	return marked;
}
void Flight::displayFlight() const
{
	cout<<"Flight #"<<id<<" from "<<deptCity.getName()<<" to "<<destCity.getName()<<"\tCost: "<<cost<<endl;
}
