//Resrevation.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _RESERVATION_H
#define _RESERVATION_H
#include <iostream>
#include <string>
class Reservation{
	public:
		Reservation(const int numPass = 0,const int flightNum = 0, const int resCode = 0, const int* rows = NULL, const char* columns = NULL); //default constructor
		Reservation(const Reservation& ); //default constructor
		~Reservation(); //destructor
		//Set Functions
		void setNumOfPass(const int);
		void setFlightNo(const int);
		void setReservationCode(const int);
		//Get Functions
		int getNumOfPass() const;
		int getFlightNumber() const;
		int getReservationCode() const;
		int* getSelectedRows() const;
		char* getSelectedColumns() const;
		
		void printReservation() const;//Print Function
		Reservation& operator=(const Reservation& right);//Assignment Operator Overloading
	private:
		int numOfPass; //number of the passenger
		int flightNo;
		int* selectedRows;
		char* selectedColumns;
		int resCode; // reservation code
		
};

#endif
