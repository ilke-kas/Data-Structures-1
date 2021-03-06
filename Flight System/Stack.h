//Stack.h
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#ifndef _STACK_H
#define _STACK_H
#include "City.h"
#include <iostream>
#include <string>
using namespace std;
class Stack{
	public:
		Stack();
		Stack(const Stack& aStack);
		~Stack();

		bool isEmpty() const;
		bool push(City newCity);
		bool pop();
		bool pop(City& stackTop);
		bool getTop(City& stackTop) const;
		City peek()const;
	private:
		struct StackNode{
			City item;
			StackNode* next;
		};
		StackNode *topPtr;
};
#endif

