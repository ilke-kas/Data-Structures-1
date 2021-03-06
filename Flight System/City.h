//City.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _CITY_H
#define _CITY_H
#include <iostream>
#include <string>
using namespace std;

class City{
	public:
		City( const string name = "", const bool marked = false);
		void setName(const string name);
		void setMarked(const bool marked);
		string getName() const;
		bool getMarked() const;
	private:
		string name;
		bool marked;
};
#endif
