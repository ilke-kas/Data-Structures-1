//Reservation.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "Reservation.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <time.h>
using namespace std;

/**
	CONSTRUCTOR
	@param numPass as the number of Passengers
	@param flightNum as the flight no
	@param reserCode as the reservation code
	@param rows as the array of the selected rows for reservation
	@param columns as the array of the selected columns for reservation
*/
Reservation::Reservation(const int numPass, const int flightNum, const int reserCode,const int* rows, const char* columns)
{
	if(numPass <= 0)
	{
		setNumOfPass(0);
		setFlightNo(0);
		resCode = 0;
		selectedColumns = NULL;
		selectedRows = NULL;
	}
	else
	{
		setNumOfPass(numPass);
		setFlightNo(flightNum);
		setReservationCode(reserCode);
		selectedColumns = new char[numPass];
		selectedRows = new int[numPass];
		//fill the arrays 
		for( int i = 0; i < numPass; i++)
		{
			selectedColumns[i] = columns[i];
			selectedRows[i] = rows[i];
		}
	}
}
/**
	COPY CONSTRUCTOR
	@param res as the reference to another Reservation Object 
*/
Reservation::Reservation(const Reservation& res)
		:numOfPass(res.numOfPass),
		flightNo(res.flightNo),
		resCode(res.resCode)
{
	if(numOfPass > 0)
	{
		selectedRows = new int[numOfPass];
		selectedColumns = new char[numOfPass];
		//fill their inside
		for( int i = 0; i < numOfPass; i++)
		{
			selectedColumns[i] = res.selectedColumns[i];
			selectedRows[i] = res.selectedRows[i];
		}
	}
	else
	{
		selectedRows = NULL;
		selectedColumns = NULL;
	}
}
/**
	DESTRUCTOR
*/
Reservation::~Reservation() //delete dynamically located arrays
{
	if(selectedRows)
		delete[] selectedRows;
	if(selectedColumns)
		delete[] selectedColumns;
}
/**
	 This function will print reservation infos
*/
void Reservation::printReservation() const
{
	cout<<"Reservations under Code "<<getReservationCode()<<" in Flight " << getFlightNumber()<<" : ";
	for(int i = 0; i < numOfPass; i++)
	{
		string s(1,selectedColumns[i]); //convert char to string
		stringstream ss;//convert int to string
		ss<<selectedRows[i];
		string seat =  ss.str() +s ;
		cout<<seat<<" ";
	}
	cout<<endl;
}
/**
	Assignment operator overloading
	@param right as the right operand for assignment operator for Reservation objects
	@return Reservation object reference 
*/
Reservation& Reservation::operator=(const Reservation& right)
{
	if(&right != this)//to avaoid self assignment
	{
		if(numOfPass != right.numOfPass)//if their size different from each other
		{
			if(numOfPass> 0)//and if wanted size is bigger than zero
			{
				delete[] selectedRows;
				delete[] selectedColumns;
			}
			numOfPass = right.numOfPass;
			flightNo = right.flightNo;
			resCode = right.resCode;
			if(numOfPass >0)
			{
				selectedRows = new int[numOfPass];
				selectedColumns = new char[numOfPass];
			}
			else
			{
				selectedRows = NULL;
				selectedColumns = NULL;
			}
		}
		for(int i = 0 ; i <numOfPass; i++)
		{
			selectedRows[i] = right.selectedRows[i];
			selectedColumns[i] = right.selectedColumns[i];
		}
	}
	return *this; // for cascading
}

//Set functions
/**
	Set the flight no
	@param no as the flight No
*/
void Reservation::setFlightNo(const int no)
{
	flightNo = no;
}
/**
	Set the number of passengers
	@param num as the number of passengers
*/
void Reservation::setNumOfPass(const int num)
{
	numOfPass = num;
}
/**
	Set the reservation code
	@param  code as the reservation code
*/
void Reservation::setReservationCode(const int code)
{
	resCode = code;
}
//get Functions
/**
	Get the flight no
	@return flightNo as the flight No
*/
int Reservation::getFlightNumber() const
{
	return flightNo;
}
/**
	Get the number of passengers
	@return numOfPass as the number of passengers
*/
int Reservation::getNumOfPass() const
{
	return numOfPass;
}
/**
	Get the reservation code
	@return resCode as the reservation code
*/
int Reservation::getReservationCode() const
{
	return resCode;
}
/**
	Get the array of selected rows for reservation
	@return selectedRows as int array
*/
int* Reservation::getSelectedRows() const
{
	return selectedRows;
}
/**
	Get the array of selected column for reservation
	@return selectedColumns as char array
*/
char* Reservation::getSelectedColumns() const
{
	return selectedColumns;
}

