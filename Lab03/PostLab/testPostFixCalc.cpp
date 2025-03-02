/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/6/2020
	File Name: testPostfixCalc.cpp
*/

#include "postfixCalculator.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "stack.h"
#include "StackNode.h"

using namespace std;

int main(){
  //Creating postfixCalculator and token;
  postfixCalculator p;
  string token;

  cout<< "enter inputs:" << endl; 


  //Stay in loop until CTRL+D is pressed. Check what kind of input token has and go into appropraite if statement + method call.
  while(cin >> token){
    cout<< "Your input was: " << token << endl;

    if(token == "+"){
      p.add();
    }
    else if(token == "-"){
      p.subtract();
    }
    else if(token == "*"){
      p.multiply();
    }
    else if(token == "/"){
      p.divide();;
    }
    else if(token == "~"){
      p.negate();
    }
    else if(token == "top"){      
       cout << "Showing top of stack: " << p.top() << endl;
    }
    else if(token == "pop"){      
       cout << "Removing top of stack... "<< endl;
       p.pop();
    }
    else if(token == "empty"){      
      if(p.empty())
	cout << "Is the stack Empty?: YES " <<  endl;
      else
	cout << "Is the stack Empty?: NO " <<  endl;
    }
    else{
      int x = stoi(token);
      p.pushNum(x);
    }    
  }
  
  return 0;
}


