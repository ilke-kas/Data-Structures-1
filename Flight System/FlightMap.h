//FlightMap.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _FLIGHTMAP_H
#define _FLIGHTMAP_H
#include "Flight.h"
#include "City.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

class FlightMap {
public:
	FlightMap( const string cityFile, const string flightFile );
	~FlightMap();
	void displayAllCities() const;
	void displayAdjacentCities( const string cityName ) const;
	void displayFlightMap() const;
	void findFlights( const string deptCity, const string destCity ) const;
	void findLeastCostFlight( const string deptCity, const string destCity ) const;
	void runFlightRequests( const string requestFile ) const;
	//delete later
	void displayFlightGraph();
private:
	Flight** FlightGraph;
	City* Cities;
	int cityNum;
	int flightNum;
	//helper functions
	string turnStackToPath(Stack aStack) const;
	int calculateCost(Stack stack) const;
	void markVisitedFlight(const string dept,const string dest) const;
	void markUnvisitedFlight(const string dept,const string dest) const;
	Flight findFlight(City c1,City c2) const;
	int findCityIndex(const string name) const;
	City* findCity(const string name) const;
	void markVisited(const string name)const;
	void markUnvisited(const string name)const;
	City* getNextCity(const string name) const;
	void printStack(Stack aStack)const;
};
#endif
