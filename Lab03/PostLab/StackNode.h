/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/6/2020
	File Name:StackNode.h
*/

/*
 * Filename: StackNode.h
 * Description: StackNode class definition
 */

#ifndef STACKNODE_H
#define STACKNODE_H

#include "stack.h"
#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class StackNode;

class StackNode {
public:
    StackNode();         // Constructor

private:
    int value;          // The value of the node!
    StackNode* next;     // The next StackNode in the List
    StackNode* previous; // The previous StackNode in the list

    // Stack needs access to value, next, and previous
friend class stack;

    // postfixCalculator needs access to value
friend class postfixCalculator;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.
};

#endif
