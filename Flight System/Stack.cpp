//Stack.cpp
/*Name-surname: ilke kas
*Student id :21803184
*Section no: 3
*/
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack():topPtr(NULL){
}
Stack::Stack(const Stack& aStack)
{
	if (aStack.topPtr == NULL)
      topPtr = NULL;  // original stack is empty

   else {
      // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;
      // copy rest of stack
      StackNode *newPtr = topPtr;
      for (StackNode *origPtr = aStack.topPtr->next;
                      origPtr != NULL;
                      origPtr = origPtr->next){
         newPtr->next = new StackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      }
      newPtr->next = NULL;
   }
}
Stack::~Stack(){

   // pop until stack is empty
   while (!isEmpty())
      pop();

}
bool Stack::isEmpty() const {

   return topPtr == NULL;

}
bool Stack::push(City newItem) {

   // create a new node
   StackNode *newPtr = new StackNode;

   // set data portion  of new node
   newPtr->item = newItem;

   // insert the new node
   newPtr->next = topPtr;
   topPtr = newPtr;

   return true;
}
bool Stack::pop() {

   if (isEmpty())
      return false;

   // stack is not empty; delete top
   else{
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}
bool Stack::pop(City& stackTop) {

   if (isEmpty())
      return false;

   // not empty; retrieve and delete top
   else{
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}
bool Stack::getTop(City& stackTop)
             const {

   if (isEmpty())
      return false;

   // stack is not empty; retrieve top
   else {
      stackTop = topPtr->item;
      return true;
   }

}
City Stack::peek()const
{
	City c;
	if (isEmpty())
      return c;

   // stack is not empty; retrieve top
   else {
       return topPtr->item;

   }
}


