//Flight.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _FLIGHT_H
#define _FLIGHT_H
#include "City.h"
#include <iostream>
#include <string>
using namespace std;

class Flight{
	public:
		Flight(const int id =0,const int cost = 0,const string deptName = "",const string destName ="");
		void setId(const int id );
		void setCost(const int cost);
		void setDest(const string dest,const bool marked);
		void setDept(const string dest,const bool marked);
		void setMarked(const bool m);
		int getId() const ;
		int getCost() const;
		City getDest() const;
		City getDept() const;
		bool getMarked() const;
		void displayFlight() const;
	private:
		int id;
		int cost;
		City deptCity;
		City destCity;
		bool marked;
};
#endif
