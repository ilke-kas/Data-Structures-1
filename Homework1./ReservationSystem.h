//ReservationSystm.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _RESERVATIONSYSTEM_H
#define _RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
class ReservationSystem {
	public:
		ReservationSystem();//constructor
		~ReservationSystem();//destructor
		void addFlight( const int flightNo, const int rowNo, const int seatNo );
		void cancelFlight( const int flightNo );
		void showAllFlights();
		void showFlight( const int flightNo );
		int makeReservation( const int flightNo, const int numPassengers,
		const int *seatRow, const char *seatCol );
		void cancelReservation( const int resCode );
		void showReservation( const int resCode );
		//Set Functions- getFunctions
		void setfSize(const int size);
		void setrSize(const int size);
		int getfSize() const;
		int getrSize() const;
	private: 
	Flight* fArray;//flight array
	Reservation* rArray;//reservation array
	int fsize;//size of the flight array
	int rsize;// size of the reservation array
	//helper functions
	int checkAndFindFlight(const int flightNo);
	string checkSelectedSeatsAvailability(const int* seatRow,const char* seatCol,const int flightNo,const int numOfPassengers);
	string createNameOfSeat(const int, const char);
	int findSeatsInFArrayByName(const string, const int);
	int checkAndFindReservation(const int resCode);
	string cancelReservationFromRArray(const int resCode);
};
#endif
