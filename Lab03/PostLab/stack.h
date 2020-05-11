/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/6/2020
	File Name: stack.h
*/

/*
 * Filename: Stack.h
 * Description: Stack class definition
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"
using namespace std;

class stack;

class stack {
public:
    // The default constructor.
    // It should initialize all private data members
    // and set up the basic list structure with the dummy head and tail nodes.
    stack();

    // The destructor.
    // It should empty the list and reclaim the memory allocated in the constructor for head and tail.
    ~stack();

    // Returns true if empty, else false
    bool empty() const;

    // Push x onto stack.
    void push(int x);

    // Pop top value off stack.
    void pop();

    // Returns top value off stack, but does not remove.
    int top();

private:
    StackNode* head;       // Dummy node representing the beginning of the list
    StackNode* tail;       // Dummy node representing the end of the list
    int count;            // Number of elements in the list

friend class StackNode; // Allow ListItr to access head and tail
friend class postfixCalculator; //Allow postfixCalculator to gain access.
};

#endif
