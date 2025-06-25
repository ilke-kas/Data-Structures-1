# CSDS 201 – Data Structures (2020)  
**Repository of Projects by İlke Kaş (21803184)**

This repository contains implementations of **four basic systems** developed for the CSDS 201 (Data Structures) course at Case Western Reserve University in Fall 2020. Each system demonstrates practical use of data structures and object-oriented programming principles in C++.

---

## 📁 Repository Structure

### 1. **Airline Seat Reservation System**
**Topic:** Class Design, Encapsulation  
**Files:**  
- `ReservationSystem.h / .cpp`  
- `Reservation.h / .cpp`  
- `Seat.h / .cpp`  
- `Flight.h`

**Functionality Implemented:**
- Create and cancel reservations for flights
- Dynamically manage seat availability
- Display reservation records and seat maps

**Data Structures Used:**
- `std::vector`: to store dynamic lists of seats and reservations
- Classes with pointers: for encapsulated object relationships

---

### 2. **Library Management System**
**Topic:** Object-Oriented Design, Class Relationships  
**Files:**  
- `LibrarySystem.h / .cpp`  
- `Student.h / .cpp`  
- `Book.h / .cpp`  
- `SimpleLibrarySystem.h / .cpp`  
- `SimpleStudent.h / .cpp`

**Functionality Implemented:**
- Add and remove students and books
- Borrow and return books
- Display library inventory and student borrow records

**Data Structures Used:**
- `std::vector`: to manage dynamic arrays of students and books
- Class composition and aggregation to model relationships

---

### 3. **Flight Map Navigation**
**Topic:** Graphs, Stack ADT  
**Files:**  
- `FlightMap.h / .cpp`  
- `Flight.h / .cpp`  
- `City.h / .cpp`  
- `Stack.h / .cpp`

**Functionality Implemented:**
- Represent cities and flights as a directed graph
- Find paths between cities using DFS-like traversal
- Track visited cities and available flights

**Data Structures Used:**
- Adjacency matrix/list (via custom classes)
- Custom Stack (LIFO) implementation for traversal
- `std::vector` for internal city and flight storage

---

### 4. **Algorithm Runtime Analysis**
**Topic:** Time Complexity, Empirical Evaluation  
**Files:**  
- `maincode.cpp`  
- `Analysis.pdf`

**Functionality Implemented:**
- Merge two sorted arrays using two different algorithms
- Measure runtime under best, worst, and average case inputs
- Visualize performance with plots and analyze time complexity

**Data Structures Used:**
- Dynamic arrays (`int*` or `std::vector`)
- Loops and index pointers for element comparisons

---

## 🧪 How to Compile

This project uses standard C++11 and doesn’t require external libraries.

Example (Airline Reservation System):

```bash
g++ -std=c++11 ReservationSystem.cpp Reservation.cpp Seat.cpp main.cpp -o reservation
./reservation
