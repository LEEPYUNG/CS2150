/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/06/2020
	File Name:postfixCalculator.cpp

        
*/

#include "postfixCalculator.h"
#include <cstdlib>
#include <iostream>
#include "stack.h"
#include "StackNode.h"
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
  if( myStack.count < 2){
    cout << "Stack did not have enough values to do operation." << endl;
    exit(-1);
  }
}

void postfixCalculator::checkEmpty2(){
  if( myStack.count < 1){
    cout << "Stack did not have enough values to do operation." << endl;
    exit(-1);
  }
}

int postfixCalculator::top(){
 return myStack.top();
}

void postfixCalculator::pop(){
  myStack.pop();
}

bool postfixCalculator::empty(){
  if(myStack.empty())
    return true;
  else
    return false;
}
