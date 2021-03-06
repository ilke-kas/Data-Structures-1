//Flight.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _FLIGHT_H
#define _FLIGHT_H
#include "Seat.h"
#include <iostream>
#include <string>
class Flight{
	public:
		Flight(const int flightNum = 0, const int row= 0, const int column = 0, const int availSeatNum = 0); //default constructor
		Flight(const Flight&); //copy constructor
		~Flight(); //destructor
		
		Flight& operator=(const Flight&);//assignment operator overloading
		//setFunctions
		void setFlightNo(const int);
		void setRowNo(const int);
		void setColumnNo(const int);
		void setAvailableSeatNum(const int);
		//Get Functions
		int getFlightNo() const;
		int getRowNo() const;
		int getColumnNo() const;
		int getAvailableSeatNum() const;
		Seat* getSeatArray() const;
		//Print functions
		void showGeneralFlightInfo() const;
		void showDetailedFlightInfo() const;	
	private:
		int flightNo;
		int rowNo;
		int columnNo;
		Seat* seatArray;
		int availableSeatNum;
		//Helper functions
		void createSeatArray(const int row,const int column);
};

#endif
