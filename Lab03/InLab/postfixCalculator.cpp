/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/03/2020
	File Name:postfixCalculator.cpp

	Sources: 
	youtube.com/watch?v=t0hJ7YOWwBY - how to implement stack STL
*/

#include "postfixCalculator.h"
#include <stack>
#include <cstdlib>
#include <iostream>
using namespace std;

postfixCalculator::postfixCalculator(){
  //  
}

//Pushes number to top of stack
void postfixCalculator::pushNum(int x){
  myStack.push(x);
}

//Add top two numbers on stack, push sum.
void postfixCalculator::add(){
    checkEmpty();
  
    int x = myStack.top();
    myStack.pop();
    int y = myStack.top();
    myStack.pop();
    int z = x + y;
    myStack.push(z);
 }
 
//Subtract top two numbers on stack,push difference.
 void postfixCalculator::subtract(){
    checkEmpty();
    
    int x = myStack.top();
    myStack.pop();
    int y = myStack.top();
    myStack.pop();
    int z = y - x;
    myStack.push(z);
 }
 
//Multiply top two numbers on stack, push product.
void postfixCalculator::multiply(){
    checkEmpty();
   
    int x = myStack.top();
    myStack.pop();
    int y = myStack.top();
    myStack.pop();
    int z = y * x;
    myStack.push(z);
}
 
//Divide top two numbers on stack, push divisor.
void postfixCalculator::divide(){
    checkEmpty();
    
    int x = myStack.top();
    myStack.pop();
    int y = myStack.top();
    myStack.pop();
    int z = y / x;
    myStack.push(z);
}
 
//Multiply top number of stack by -1 and return it.
void postfixCalculator::negate(){
  checkEmpty2();
   
  int x = myStack.top();
  myStack.pop();
  int y = x * -1;
  myStack.push(y);
}

void postfixCalculator::checkEmpty(){
  if( myStack.size() < 2){
    cout << "Stack did not have enough values to do operation." << endl;
    exit(-1);
  }
}

void postfixCalculator::checkEmpty2(){
  if( myStack.size() < 1){
    cout << "Stack did not have enough values to do operation." << endl;
    exit(-1);
  }
}
