/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/6/2020
	File Name:stack.cpp
*/

#include "stack.h"
#include <iostream>
#include "StackNode.h"
using namespace std;

// The default constructor.
// It should initialize all private data members
// and set up the basic list structure with the dummy head and tail nodes.
stack::stack(){
 count = 0;

 //Initializing a node pointer to a StackNode object.
 head = new StackNode();
 tail = new StackNode();
 
 head -> next = tail;
 head -> previous = NULL;
 tail -> previous = head;
 tail -> next = NULL;
}

// The destructor.
// It should empty the list and reclaim the memory allocated in the constructor for head and tail.
stack::~stack() {
  
  //makEmpty() deletes all nodes except the head and tail.
  // makeEmpty();
  
  //Because the head and tails were not deleted, delete them manually.
  delete head;
  delete tail;
}

// Returns true if empty, else false
 bool stack::empty() const {
   if(count == 0)
     return true;
   else
     return false;
 }

// Pushs x onto stack.
 void stack::push(int x){
   StackNode* n = new StackNode(); //Creates a pointer and Node
   n->value = x; //sets value to x.

   //Make connections with pointers.
   n->next = tail; 
   n->previous= tail -> previous;

   //Fixes pointers between nodes.
   tail -> previous -> next = n;
   tail -> previous = n;

   //Adds count.
   count++;
 }

// Pop top value off stack.
 void stack::pop(){

   //Sets the 2nd to last node's next pointer to tail.
   tail -> previous -> previous -> next = tail;
   //Sets tail's previous to 2nd to last node.
   tail -> previous = tail -> previous -> previous;

   //Decrement count
   count--;
 }

//Returns top value off stack, but does not remove.
 int stack::top(){
   return tail -> previous->value;
 }

 
  
 
