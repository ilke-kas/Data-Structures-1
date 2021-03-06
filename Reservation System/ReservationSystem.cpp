//ReservationSystem.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "ReservationSystem.h"
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <string>
#include <iostream>
/**
	CONSTRUCTOR
*/
ReservationSystem::ReservationSystem()
{
	//initialize data members
	setfSize(0);
	setrSize(0);
	fArray = NULL;
	rArray = NULL;
}
/**
	DESTRUCTOR
*/
ReservationSystem::~ReservationSystem()
{
	//delete the dynamically allocated arrays for mem leak
	if(fArray)
		delete[] fArray;
	if(rArray)
		delete[] rArray;
}
/**
	 This function will add flight with unique flight number
	 to the array of the ReservationSystem with given arguments
	 @param flightNo 
	 @param rowNo as the row number of the flight
	 @param seatNo as the column number of the flight
*/
void ReservationSystem::addFlight(const int flightNo,const int rowNo, const int seatNo)
{
	//check whether flightNo is already taken or not
	if(checkAndFindFlight(flightNo) != -1)// if it is, give error message, do not add flight
	{
		cout<<"Flight "<<flightNo <<" is already exists."<<endl;
	}
	else if(rowNo <= 0 || seatNo <= 0)//check the positivity of row and column no
	{
		cout<<"Invalid row and/or seat values"<<endl;
	}
	else
	{
		//if fsize = 0 , then first create fArray 
		if(fsize == 0)
		{
			fArray = new Flight[1];
			fsize++;
			//create the flight according to inputs
			Flight f(flightNo, rowNo,seatNo);
			//add it to the array
			fArray[0] = f;
		}
		else
		{
			//create new array with fsize+1
			Flight* newArr = new Flight[fsize +1];
			//fill its inside with old array
			for(int i = 0; i <fsize; i++)
			{
				newArr[i] = fArray[i];
			}
			//delete old array
			delete[] fArray;
			//create the flight according to inputs
			Flight f(flightNo, rowNo,seatNo);
			//add it to the new array
			newArr[fsize] = f;
			fsize++;
			//since with delete old array in the heap is deleted but pointer remains 
			fArray = newArr;
		}
		cout<<"Flight "<< flightNo << " has been added."<<endl;//show the message
	}
}
/**
	This function will find the position of the given flightNo in the flight array 
	@param flightNo as the searched flight's no
	@return -1  if cannot find the flight, else return the index of it
*/
int ReservationSystem::checkAndFindFlight(const int flightNo)
{
	//traverse the fArray
	for(int i = 0; i <fsize; i++)
	{
		if(fArray[i].getFlightNo() == flightNo)
			return i; //return the index
	}
	return -1; //if it cannot find it 	
}
/**
	This function will show the all flights in fArray currently operated
*/
void ReservationSystem::showAllFlights()
{
	if(fsize == 0)
		cout<<"No flights exist."<<endl;
	else
	{
		cout<<"Flights currently operated: "<<endl;
		//traverse the fArray
		for(int i = 0; i <fsize;i++)
		{
			fArray[i].showGeneralFlightInfo();
		}
	}
}
/**
	This function will show detailed information about the flight whose flightNo is given
	@param flightNo as the wanted flight's no
*/
void ReservationSystem::showFlight(const int flightNo)
{
	//Find the index of the flightNo
	int index = checkAndFindFlight(flightNo);
	if(index == -1)
		cout<<"Flight "<<flightNo<<" does not exist."<<endl;
	else
		fArray[index].showDetailedFlightInfo();
}
/**
	This function will make reservation if it cannot do that return -1
	@param flightNo for the make reservation to which flight
	@param numPassengers as the number of the passengers 
	@param seatRow as the selected rows for reservation
	@param seatCol as the selected columns for reservation
	@return -1 if cannot make the reservation,otherwise unique reservationCode
*/
int ReservationSystem::makeReservation(const int flightNo, const int numPassengers,	const int *seatRow, const char *seatCol)
{
	//check the flight no
	int indexOfFlight = checkAndFindFlight(flightNo);
	if(indexOfFlight == -1)
	{
		cout<<"There is not any flight with number " << flightNo<<endl;
		return -1;
	}
	else 
	{
		//check the availablity of seats
		string seats = checkSelectedSeatsAvailability(seatRow,seatCol,flightNo,numPassengers);
		if(seats != "")
		{
			cout<< seats<< " are not available."<<endl;
			return -1;
		}
		else 
		{
			//make reservation 
			//create unique reservation code 
			srand(time(0));
			int resCode = rand()%1000;
			for(int i = 0;i <rsize;)
			{
				if(resCode == rArray[i].getReservationCode())
					resCode = rand()%1000;
				else 
					i++;
			}
			//create ReservationBy this code
			Reservation r(numPassengers,flightNo,resCode,seatRow,seatCol);
			//add it to the array but if rzie = 0 first create it
			if(rsize == 0)
			{
				rArray = new Reservation[1];
				rsize++;
				rArray[0] = r;
			}
			else
			{
				//create new array with +1 size
				Reservation* newArr = new Reservation[rsize+1];
				for(int i = 0; i <rsize;i++) //copy the old arrays content
				{
					newArr[i] = rArray[i];
				}
				delete[] rArray; //delete old arrays content from heap
				newArr[rsize ] = r; //add the created object
				rsize++;//increment the size
				rArray = newArr;//point to new created array in the heap
			}
			//reserved seats
			for(int i = 0; i <numPassengers; i++)//traverse the selected rows and columns 
			{
				string name = createNameOfSeat(seatRow[i], seatCol[i]);//create the name of the seats in the selected arrays
				int seatIndex = findSeatsInFArrayByName(name,indexOfFlight);//fin this seat's index in flight array
				(fArray[indexOfFlight].getSeatArray())[seatIndex].setReserved(true);//make them reserved
				fArray[indexOfFlight].setAvailableSeatNum(fArray[indexOfFlight].getAvailableSeatNum()-1);//update the available seat number
			}
		}
		return rArray[rsize-1].getReservationCode();//return reservation code
	}
 } 
 /**
 	 This function will check the selected seats availability for make reservation
 	 @param seatRow as the selected rows for reservation
 	 @param seatCol as the selected columns for reservation
 	 @param flightNo of the flight
 	 @param numOfPassengers as the number of passengers
 	 @return string seats which shows the reserved seats in selected arrays
 */
 string ReservationSystem::checkSelectedSeatsAvailability(const int* seatRow,const char* seatCol,const int flightNo,const int numOfPassengers)
 {
 	string seats = "";
 	int indexOfFlight = checkAndFindFlight(flightNo);
 	for(int i = 0; i <numOfPassengers; i++)
 	{
 		string s = createNameOfSeat(seatRow[i], seatCol[i]);
 		int indexOfs = findSeatsInFArrayByName(s,indexOfFlight);
 		if((indexOfs != -1) &&(fArray[indexOfFlight].getSeatArray())[indexOfs].getReserved())
 			seats = seats + " " + s;
	 }
	 return seats;
 }
 /**
 	This function will create the name of seats by applying string operations
 	@param row 
 	@param column
 	@return name of seat
 */
 string ReservationSystem::createNameOfSeat(const int row, const char column)
 {
 	string name;
 	string s(1, column);
 	stringstream ss;
 	ss<<row;
 	name = ss.str() +s;
 	return name;
 }
 /**
 	This function find the seat index of flight whose index in flight array is given by using name of the seat
 	@param name as the name of the seat
 	@param indexOfFlight as the flight's place in the flight array
 	@return index, or if it cannot find it return -1
 */
 	int ReservationSystem::findSeatsInFArrayByName(const string name, const int indexOfFlight)
 	{
 		int sizeOfSeatArray = (fArray[indexOfFlight].getRowNo()) * (fArray[indexOfFlight].getColumnNo());
 		for( int i = 0; i < sizeOfSeatArray; i++)
 		{
 			if(((fArray[indexOfFlight].getSeatArray())[i]).getName() == name)
 				return i;
		 }
		 return -1;
	 }
/**
	This function will show the reservation whose reservation code is given
	@param resCode as the reservation code
*/
void ReservationSystem::showReservation( const int resCode )
{
	int index = checkAndFindReservation(resCode);
	if(index == -1)
	{
		cout<<"No reservations are found under the code "<< resCode<<endl;
	}
	else
	{
		rArray[index].printReservation();
	}	
}
/**
	This function will find the index of reservation whose code is given in rArray
	if cannot find it will return -1,
	@param resCode as the reservation code
	@return the index of the reservation in array
*/
int ReservationSystem::checkAndFindReservation(const int resCode)
{
	//traverse the r array
	for(int i = 0; i <rsize;i++)
	{
		if(resCode == rArray[i].getReservationCode())
			return i;
	}
	return -1;
}
/**
	This function will cancel the flight
	@param flightNo as the flight which is wanted to be canceled
*/
void ReservationSystem::cancelFlight(const int flightNo)
{
	//check whether given no exists or not
	int index = checkAndFindFlight(flightNo);
	if(index == -1)
	{
		cout<<"Flight "<< flightNo <<" does not exist."<<endl;
	}
	else
	{
		//cancel all reservations for this flight 
		for( int i = 0; i<rsize;i++)
		{
			if(rArray[i].getFlightNumber() == flightNo)
			{
				//cancel the reservation
				cancelReservationFromRArray(rArray[i].getReservationCode());
				i = -1; //since the size of r changed look from the beggining again
			}
		}
		//create a new array with size fsize-1
		Flight* newArr = new Flight[fsize-1];
		//copy the old array except the index element
		for(int i = 0, k = 0; i<fsize; i++)
		{
			if(i == index)
				continue;
			else
			{
				newArr[k] = fArray[i];
				k++;
			}	
		}
		//delete the old array
		delete[] fArray;
		//decrement the size
		fsize--;
		//assign fArray to new Array
		fArray = newArr;
		cout<<"Flight " <<flightNo<<" and all its reservations are cancelled."<<endl;
	}
}
/**
	This function will cancel the reservation whose resCode is given
	@param resCode as the reservation code
*/
void ReservationSystem::cancelReservation(const int resCode)
{
	int index = checkAndFindReservation(resCode);
	if(index== -1)
	{
		cout<<"No reservations are found under code "<<resCode<<endl;
	}
	else
	{
		int flightNo =rArray[index].getFlightNumber();
		string seats =cancelReservationFromRArray(resCode);
		cout<<"Reservation for the seats "<<seats<< " is canceled in Flight " <<flightNo<<endl;
	}
}
/**
	This function is written for both use of cancel Flight and CancelReservation to perform common cancel operation
	@param resCode as the reservation code
	@return seats as the name of the unreserved seats
*/
string ReservationSystem::cancelReservationFromRArray(const int resCode)
{
	int index = checkAndFindReservation(resCode);
	//get the flight no and index of it in fArray
		int flightNo =rArray[index].getFlightNumber();
		int flightIndex = checkAndFindFlight(flightNo);
		string seats = "";
		for(int i = 0;i <rArray[index].getNumOfPass();i++)
		{
			string nameOfSeat = createNameOfSeat((rArray[index].getSelectedRows())[i],(rArray[index].getSelectedColumns()[i]));
			seats = seats + " " + nameOfSeat;
			int seatIndex = findSeatsInFArrayByName(nameOfSeat,flightIndex);
			//reverse its availability
			(fArray[flightIndex].getSeatArray())[seatIndex].setReserved(false);
			//update num of available seats
			(fArray[flightIndex].setAvailableSeatNum(fArray[flightIndex].getAvailableSeatNum()+1));
		}
		//create new array with size rsize-1
		Reservation* newArr = new Reservation[rsize-1];
		//copy old array's content except index element
		for(int i = 0,k = 0;i<rsize;i++)
		{
			if(i == index)
				continue;
			else
			{
				newArr[k] = rArray[i];
				k++;
			}
		}
			//delete old array
			delete[] rArray;
			rsize--;
			rArray = newArr;
			return seats;
}
//set- get functions
/**
	Set the size of the flight array
	@param size 
*/
void ReservationSystem::setfSize(const int size)
{
	fsize = size;
}
/**
	Set the size of the reservation array
	@param size 
*/
void ReservationSystem::setrSize(const int size)
{
	rsize = size;
}
/**
	Get the size of the flight array
	@return fsize 
*/
int ReservationSystem::getfSize() const
{
	return fsize;
}
/**
	Get the size of the reservation array
	@return rsize 
*/
int ReservationSystem::getrSize() const
{
	return rsize;
}


