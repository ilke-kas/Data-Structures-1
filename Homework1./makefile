# Project: ReservationSystem
# Makefile created by Dev-C++ 5.11

CC=g++
CFLAGS=-c -Wall

all: do

do: Seat.o Flight.o Reservation.o ReservationSystem.o  main.o
	$(CC) Seat.o Flight.o Reservation.o ReservationSystem.o  main.o -o system

Seat.o: Seat.cpp
	$(CC) $(CFLAGS) Seat.cpp

Flight.o: Flight.cpp
	$(CC) $(CFLAGS) Flight.cpp

Reservation.o: Reservation.cpp
	$(CC) $(CFLAGS) Reservation.cpp

ReservationSystem.o: ReservationSystem.cpp
	$(CC) $(CFLAGS) ReservationSystem.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o system