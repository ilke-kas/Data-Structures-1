//Flight.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include <iostream>
#include <string>
#include "Flight.h"
using namespace std;
/*
	DEFAULT CONSTRUCTOR
	@param flightNum as the flight No 
	@param row as the row number
	@param column as the column number
	@param availSeatNum as the available (not reserved seat number)
*/
Flight::Flight(const int flightNum,const int row,const int column, const int availSeatNum)
{
	if(row > 0 && column > 0) //check the positivity of the values of row and column
	{
		//create the flight
		setFlightNo(flightNum);
		setRowNo(row);
		setColumnNo(column);
		setAvailableSeatNum(column*row);
		createSeatArray(row,column);
	}
	else 
	{
		setFlightNo(0);
		setRowNo(0);
		setColumnNo(0);
		setAvailableSeatNum(0);
		seatArray = NULL;		
	}
}
/*
	COPY CONSTRUCTOR
	@param f as the reference to the another Flight Object
*/
Flight::Flight(const Flight& f)
		:flightNo(f.flightNo),
		rowNo(f.rowNo),
		columnNo(f.columnNo),
		availableSeatNum(f.availableSeatNum)
{
	int size = f.columnNo * f.rowNo;
	if(size > 0)
	{
		seatArray = new Seat[size];
		for(int i = 0; i <size;i++)
		{
			seatArray[i] = f.seatArray[i];
		}
	}
	else 
	{
		seatArray = NULL;
	}
}
/*
*DESTRUCTOR
*/
Flight::~Flight()
{
	if(seatArray)
		delete[] seatArray;
}
/**
	Assignment Operator Overloading
	@param right as the right operand for assignment operator for Flight objects
	@return Flight object reference 
*/
Flight& Flight::operator=(const Flight& right)
{
	if(&right != this) //to avoid self-assignment
	{
		int size = rowNo* columnNo;
		int rsize = right.columnNo * right.rowNo;
		if(size != rsize)// if their size are not same
		{
			if(size > 0 )//delete old array 
				delete[] seatArray;
			//copy other values
			rowNo = right.rowNo;
			columnNo = right.columnNo;
			availableSeatNum = right.availableSeatNum;
			flightNo = right.flightNo;
			size = rsize;
			if(size > 0) //if new size is greater than zero, then create new array
				seatArray = new Seat[size];
			else
				seatArray = NULL;
		}
		//fill inside the new array
		for(int i = 0; i <size ; i++)
			seatArray[i] = right.seatArray[i];
	}
	return *this; //to cascading 
}
/**Helper function to constructor
	It created dynamically seat array with given size and
	fill inside of this array with seats which are not reserved yet
	@param row as the row number
	@param column as the column number
*/
void Flight::createSeatArray(const int row, const int column)
{
	int size = column* row;
	if(size > 0 )
	{
		seatArray = new Seat[size]; //create dynamically seat array
		//fill inside of it by creating seats
		for(int i = 1, k= 0; i <= row; i++)
		{
			for (int j = 0; j <column; j++)
			{
				Seat s(i,65+j);
				seatArray[k] = s;
				k++;
			}
		}
	}
	else
	{
		seatArray = NULL;
	}
}
//print functions
/**
	This function will print the general info about this Flight(flight code and available seat num)
*/
void Flight::showGeneralFlightInfo() const
{
	cout<<"Flight "<<getFlightNo()<< " ("<< getAvailableSeatNum()<< " available seats)"<<endl;
}
/**
	This function will print the detailed info about this Flight
*/
void Flight::showDetailedFlightInfo() const
{
	cout<<"Flight "<<getFlightNo()<<" has "<<getAvailableSeatNum()<<" available seats."<<endl;
	cout<<endl;
	//print the charachter row
	cout<<" ";
	for(int i = 0; i < getColumnNo(); i++)
	{
		cout<<static_cast<char>(65+i);
	}
	cout<<endl;
	//print the seatArray  situation
	for(int i = 0, k = 0; i< getRowNo(); i++)
	{
		cout<<i+1;
		for(int j = 0; j < getColumnNo(); j++)
		{
			cout<<(seatArray[k].getReserved() ? "x":"o");
			k++;
		}
		cout<<endl;
	}
}

//Set Functions
/**
	Set the flight number
	@param flightNum as the flight No
*/
void Flight::setFlightNo(const int flightNum)
{
	flightNo = flightNum;
}
/**
	Set the column no
	@param column as the fcolumn number
*/
void Flight::setColumnNo(const int column)
{
	columnNo = column;
}
/**
	Set the row no
	@param crow as the row number
*/
void Flight::setRowNo(const int row)
{
	rowNo = row;
}
/**
	Set the available seat number
	@param num as the number od the seats
*/
void Flight::setAvailableSeatNum(const int num)
{
	availableSeatNum = num;
}

//get Functions
/**
	Get the flight no
	@return flightNo 
*/
int Flight::getFlightNo() const
{
	return flightNo;
}
/**
	Get the row no
	@return rowNo 
*/
int Flight::getRowNo() const
{
	return rowNo;
}
/**
	Get the column no
	@return columnNo 
*/
int Flight::getColumnNo() const
{
	return columnNo;
}
/**
	Get the available Seat number
	@return availableSeatNum
*/
int Flight::getAvailableSeatNum() const
{
	return availableSeatNum;
}
/**
	Get the seatArray
	@return seatArray
*/
Seat* Flight::getSeatArray() const
{
	return seatArray;
}
