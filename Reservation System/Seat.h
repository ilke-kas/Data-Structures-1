//Seat.h file
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include <string>
#ifndef _SEAT_H
#define _SEAT_H
using namespace std;
class Seat{
	public:
		Seat(const int = 0,const char =' ',const bool =false);//default constructor
		Seat(const Seat&); //copy constructor
		~Seat();//destructor
		//Set Functions
		void setRow(const int r);
		void setColumn(const char c);
		void setReserved(const bool r);
		//get Functions
		int getRow() const;
		char getColumn() const;
		bool getReserved() const;
		string getName() const;
	private:
		bool reserved;//availability situation
		int row;
		char column;
		string name;
};

#endif
