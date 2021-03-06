//FlightMap.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "Flight.h"
#include "City.h"
#include "Stack.h"
#include "FlightMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    //Initialize all data Members first
    FlightGraph = NULL;
    Cities = NULL;
    cityNum = 0;
    flightNum = 0;
    //Read city file
	string fileName = cityFile;
	string txt;
	string space;
	string name;
	ifstream inputFile,inputFile3;
	ifstream inputFile2;
	inputFile.open(fileName.c_str(),ios_base::in);
	while(inputFile.eof()== false) //first find the number of the cities in the array
	{
	//	getline(inputFile,txt,'\r');
		cityNum++;
		getline(inputFile,txt,'\n');
	}
	inputFile.close();
	//create cities array
	Cities = new City[cityNum];
	//read file for content
	int index = 0;
	inputFile2.open(fileName.c_str(),ios_base::in);
	while(inputFile2.eof()== false) //fill the inside of the cities array with given cities in txt file
	{
		getline(inputFile2,name,'\n');
		City c(name,false);
		Cities[index] = c;
		index++;
		//getline(inputFile2,name,'\n');
	}
	inputFile2.close();
	//create FlightGraph as adjacency matrix
	FlightGraph = new Flight*[cityNum];
	for(int i = 0; i <cityNum; i++)
		FlightGraph[i] = new Flight[cityNum];

	//read flight file
	string line;
	string fileName2 = flightFile;
	string origname;
	string destname;
	string idstr;
	string coststr;
	int id;
	int cost;
	inputFile3.open(fileName2.c_str(),ios_base::in);
	while(inputFile3.eof()== false) //fill the inside of the cities array with given cities in txt file
	{
		getline(inputFile3,origname,',');
		getline(inputFile3,destname,',');
		getline(inputFile3,idstr,',');
		getline(inputFile3,coststr,'\n');
		
		//convert idstr and coststr to int
		stringstream ss;
		stringstream ss2;
		ss<<idstr;
		ss>>id;
		ss2<<coststr;
		ss2>>cost;
		//create Flight
		Flight F(id,cost,origname,destname);
		flightNum++;
		//put it to the matrix
		int destindex = findCityIndex(destname);
		int origindex = findCityIndex(origname);
		if((destindex != -1) && (origindex != -1))
			FlightGraph[origindex][destindex] = F;
	}
	inputFile3.close();
}
FlightMap::~FlightMap()
{
	//delete Flight Graph
 	if(cityNum != 0)
 	{
 	for ( int i = 0; i < cityNum; i++ )
 		delete [] FlightGraph[i];
 	delete[] FlightGraph;
 		delete []Cities;
	}
}
void FlightMap::displayAllCities() const
{
	for(int i = 0; i <cityNum; i++)
		cout<<Cities[i].getName()<< ",";
	cout<<endl;
}
void FlightMap::displayAdjacentCities( const string cityName ) const
{
	cout<<cityName<<"->";
	int ind = findCityIndex(cityName);
	if(ind != -1)
	{
		for(int i = 0; i< cityNum; i++)
		{
			if(FlightGraph[ind][i].getId() != 0)
				cout<<Cities[i].getName()<<",";
		}
	}
	cout<<endl;
}
void FlightMap::displayFlightMap() const
{
	for(int i = 0; i <cityNum;i++)
		displayAdjacentCities(Cities[i].getName());
}

City* FlightMap::findCity(const string name) const
{
	//traverse the city array
	for(int i = 0; i <cityNum; i++)
	{
		if(Cities[i].getName() == name )
			return (Cities + i);
	}
	return NULL;
}

int FlightMap::findCityIndex(const string name) const
{
    //traverse the city array
	for(int i = 0; i <cityNum; i++)
	{
		if(Cities[i].getName() == name )
			return i ;
	}
	return -1;
}
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void FlightMap::findFlights( const string deptCity, const string destCity ) const
{
	cout<<"Request is to fly from "<<deptCity<<" to "<<destCity<<":"<<endl;
	Stack aStack;
	City hold;
	int count = 1;
	int found = 0;
	//unvisit all cities
	for(int i = 0; i<cityNum; i++)
		markUnvisited(Cities[i].getName());
	//unvisit all flights
	for(int i = 0; i<cityNum;i++)
		for(int j = 0; j<cityNum;j++)
			markUnvisitedFlight(Cities[i].getName(),Cities[j].getName());
			
	City* orig = findCity(deptCity);
	City* dest = findCity(destCity);
	//push the origin city to the stack
	aStack.push(*orig);
	markVisited(deptCity);
	
while(!aStack.isEmpty()){

	City topCity;
	aStack.getTop(topCity);
	if(count != 2)
		markUnvisited(hold.getName());
	City* nextCity = getNextCity(topCity.getName());
	if(nextCity == NULL)
	{
		aStack.pop();
		if(aStack.isEmpty() &&(found == 0))
		{
			cout<<"Sorry. HPAir does not fly from "<<deptCity<<" to "<<destCity<<endl;
			break;
		}
	}
	else
	{
		string nextName = nextCity->getName();
		while(!aStack.isEmpty() && (nextName != destCity))
		{
			if(nextCity == NULL)
			{
				aStack.pop();
				count--;
				if(aStack.isEmpty())
				{
					if(found == 0)
						cout<<"Sorry. HPAir does not fly from "<<deptCity<<" to "<<destCity<<endl;
					break;
				}
			}
			else
			{	
				if(count == 1)
				{
					markVisitedFlight(topCity.getName(),nextCity->getName());
					hold = *nextCity;
				}
				markVisited(nextName);
				aStack.push(*nextCity);
				count++;
				
			}
			if(!aStack.isEmpty())
			{
				aStack.getTop(topCity);
				nextCity = getNextCity(topCity.getName());
				if(nextCity == NULL)
					nextName = "";
				else
					nextName = nextCity->getName();
			}
		}
		if(aStack.isEmpty())
		{
			break;
		}
		else if(nextCity->getName() == destCity)
		{
			found++;
			Stack bStack = aStack;
			bStack.push(*nextCity);
			printStack(bStack);
			aStack.pop();
			count--;
		}
	}	
}
}
void FlightMap::findLeastCostFlight(const string deptCity, const string destCity) const
{
	int leastCost = 0;
	Stack leastStack;
	Stack bStack;
	string path;
	cout<<"Request is to fly from "<<deptCity<<" to "<<destCity<<":"<<endl;
	Stack aStack;
	City hold;
	int count = 1;
	int found = 0;
	//unvisit all cities
	for(int i = 0; i<cityNum; i++)
		markUnvisited(Cities[i].getName());
	//unvisit all flights
	for(int i = 0; i<cityNum;i++)
		for(int j = 0; j<cityNum;j++)
			markUnvisitedFlight(Cities[i].getName(),Cities[j].getName());
			
	City* orig = findCity(deptCity);
	City* dest = findCity(destCity);
	//push the origin city to the stack
	aStack.push(*orig);
	markVisited(deptCity);
	
while(!aStack.isEmpty()){

	City topCity;
	aStack.getTop(topCity);
	if(count != 2)
		markUnvisited(hold.getName());
	City* nextCity = getNextCity(topCity.getName());
	if(nextCity == NULL)
	{
		aStack.pop();
		if(aStack.isEmpty() &&(found == 0))
		{
			cout<<"Sorry. HPAir does not fly from "<<deptCity<<" to "<<destCity<<endl;
			break;
		}
	}
	else
	{
		string nextName = nextCity->getName();
		while(!aStack.isEmpty() && (nextName != destCity))
		{
			if(nextCity == NULL)
			{
				aStack.pop();
				count--;
				if(aStack.isEmpty())
				{
					if(found == 0)
						cout<<"Sorry. HPAir does not fly from "<<deptCity<<" to "<<destCity<<endl;
					break;
				}
			}
			else
			{	
				if(count == 1)
				{
					markVisitedFlight(topCity.getName(),nextCity->getName());
					hold = *nextCity;
				}
				markVisited(nextName);
				aStack.push(*nextCity);
				count++;
				
			}
			if(!aStack.isEmpty())
			{
				aStack.getTop(topCity);
				nextCity = getNextCity(topCity.getName());
				if(nextCity == NULL)
					nextName = "";
				else
					nextName = nextCity->getName();
			}
		}
		if(aStack.isEmpty())
		{
			break;
		}
		else if(nextCity->getName() == destCity)
		{
			found++;
		    bStack = aStack;
			bStack.push(*nextCity);
			printStack(bStack);
			int cost = calculateCost(bStack);
			if((found == 1)||(leastCost > cost))
			{
				leastCost = cost;
				leastStack = bStack;
			}
			path = turnStackToPath(leastStack);
			aStack.pop();
			count--;
		}
	}	
}
cout<<"A least cost path from "<<deptCity<<" to "<<destCity<<" is "<<path<<" and its cost is "<<leastCost<<" TL"<<endl;
}

string FlightMap::turnStackToPath(Stack aStack) const
{
	//create temp stack
	string path = "";
	Stack temp;
	while(!aStack.isEmpty())
	{
		City topCity;
		aStack.getTop(topCity);
		//push it to the temp stack
		temp.push(topCity);
		aStack.pop();
	}
	//find fligts and print them
		City c1;
		temp.pop(c1);
		path.append(c1.getName());
	while(!temp.isEmpty())
	{
		City c2;
		temp.pop(c2);
		path.append("->");
		path.append(c2.getName());
	}
	return path;
}

int FlightMap::calculateCost(Stack aStack)const
{
	int totalCost = 0;
	//create temp stack
	Stack temp;
	while(!aStack.isEmpty())
	{
		City topCity;
		aStack.getTop(topCity);
		//push it to the temp stack
		temp.push(topCity);
		aStack.pop();
	}
	//find fligts and print them
		City c1;
		temp.pop(c1);
	while(!temp.isEmpty())
	{
		City c2;
		temp.pop(c2);
		Flight F = findFlight(c1,c2);
		totalCost = totalCost + F.getCost();
		c1 =c2;
	}
	return totalCost;
}
void FlightMap::runFlightRequests(const string requestFile) const
{
	string fileName = requestFile;
	ifstream inputFile;	
	inputFile.open(fileName.c_str(),ios_base::in);
	//Continue until the end of the file
	while(inputFile.eof() == false)
	{
		string destCity;
		string deptCity;
		//Read deptCity until comma
		cout<<destCity<<deptCity<<endl;
		getline(inputFile,deptCity,',');
		getline(inputFile,destCity,'\n');
		findLeastCostFlight(deptCity,destCity);
	}
}
void FlightMap::printStack(Stack aStack) const
{
	int totalCost = 0;
	//create temp stack
	Stack temp;
	while(!aStack.isEmpty())
	{
		City topCity;
		aStack.getTop(topCity);
		//push it to the temp stack
		temp.push(topCity);
		aStack.pop();
	}
	//find fligts and print them
		City c1;
		temp.pop(c1);
	while(!temp.isEmpty())
	{
		City c2;
		temp.pop(c2);
		Flight F = findFlight(c1,c2);
		totalCost = totalCost + F.getCost();
		F.displayFlight();
		c1 =c2;
	}
	cout<<"Total Cost............."<<totalCost<<endl;
	cout<<endl;
}

Flight FlightMap::findFlight(City c1,City c2) const
{
	//find the indexes of cities
	int ind1 = findCityIndex(c1.getName());
	int ind2 = findCityIndex(c2.getName());
	if((ind1 != -1) && (ind2!= -1))
		return FlightGraph[ind1][ind2];
}


City* FlightMap::getNextCity(string name) const
{
	int ind = findCityIndex(name);
	if(ind != -1)
	{
		for(int i = 0; i< cityNum; i++)
		{
			if((FlightGraph[ind][i].getId() != 0 )&& (!(Cities[i].getMarked()))&&(!(FlightGraph[ind][i].getMarked())))
			{
				return (Cities+i);
			}		
		}
	}
	return NULL;
	
}	
void FlightMap::markVisitedFlight(const string dept,const string dest) const
{
	int dpt = findCityIndex(dept);
	int dst = findCityIndex(dest);
	if((dpt != -1)&&(dst != -1))
		FlightGraph[dpt][dst].setMarked(true);
}
void FlightMap::markUnvisitedFlight(const string dept,const string dest) const
{
	int dpt = findCityIndex(dept);
	int dst = findCityIndex(dest);
	if((dpt != -1)&&(dst != -1))
		FlightGraph[dpt][dst].setMarked(false);
}	
void FlightMap::markVisited(const string name) const
{
	int ind = findCityIndex(name);
	if(ind != -1)
		Cities[ind].setMarked(true);
}
void FlightMap::markUnvisited(const string name) const
{
	int ind = findCityIndex(name);
	if(ind != -1)
		Cities[ind].setMarked(false);
}
