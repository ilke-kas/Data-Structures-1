//Seat.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "Seat.h"
#include <string>
#include <iostream>
#include<sstream>
using namespace std;
/**
	Default Constructor
	@param r as row number
	@param c as column number
	@param resrv as reserved or availibility of te seat
*/
Seat::Seat(const int r,const char c, const bool reserv)
{
	setRow(r);
	setColumn(c);
	setReserved(reserv);
	//create name 
	string s(1,c); //convert char to string
	stringstream ss;//convert int to string
	ss<<r;
	name = ss.str() +s ;//create name
}
/*
	Copy constructor
	@param Seat reference to another Seat object
*/
Seat::Seat(const Seat& s)
{
	setRow(s.row);
	setColumn(s.column);
	setReserved(s.reserved);
	name = s.name;
}
/**
	Destructor
*/
Seat::~Seat()
{
}
//set functions
/**
	Set the row number
	@param r as row number
*/
void Seat::setRow(const int r)
{
	row = r;
}
/**
	Set the column number
	@param c as column number
*/
void Seat::setColumn(const char c)
{
	column = c;
}
/**
	Set the reserved situtaion
	@param r as boolean type for reserved situation
*/
void Seat::setReserved(const bool r)
{
	reserved = r;
}
//Get functions
/**
	Return the column number
	@return column
*/
char Seat::getColumn() const
{
	return column;
}
/**
	Return the name of the seat
	@return name
*/
string Seat::getName() const
{
	return name;
}
/**
	Return the row number
	@return row
*/
int Seat::getRow() const
{
	return row;
}
/**
	Return the reserved situation
	@return reserved
*/
bool Seat::getReserved() const
{
	return reserved;
}

