/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/3/2020
	File Name: postfixCalculator.h
*/

/*
 * Filename: postfixCalculator.h
 * Description: postfixCalculator class definition. Also includes function prototypes and fields.
 */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <stack>

class postfixCalculator;

class postfixCalculator {

public:	
	//Constructor - implemented by stack STL
	postfixCalculator();
		
	//Add number to stack.
	void pushNum(int x);
	//Add top two numbers on stack, push sum.
	void add();
	//Subtract top two numbers on stack, push 		difference.
	void subtract();
	//Multiply top two numbers on stack, push 		product.
	void multiply();
	//Divide top two numbers on stack, push divisor.
	void divide();
	//Multiply top number of stack by -1 and push it.
	void negate();
	//Checks if there is atleast 2 inputs in stack.
	void checkEmpty();
	//Checks if there is atleast 1 input in stack.
	void checkEmpty2();

	std::stack<int> myStack;
	
	
};

#endif
