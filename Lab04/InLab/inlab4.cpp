/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/11/2020
	File Name: inlab4.cpp
*/

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cfloat>

using namespace std;

union foo{
  double f;
  int *x;
}bar;





int main(){


  //  bar.f=1.0;
  // cout << bar.x << endl;
  

  /*
  //WorkSheet

  //Checking 0 in Hex
  int a = 0;
  unsigned int b = 0;
  float c = 0.0;
  double d = 0;
  char e = '0';
  bool g = false;

  cout << "Value of a: " << a << endl;
  cout << "Value of b: " << b << endl;
  cout << "Value of c: " << c << endl;
  cout << "Value of d: " << d << endl;

  */
  
  
  /*
  //Representation in memory
  bool a = true;
  char b = 'a';
  int c = 5;
  double d = 6.0;
  int* e = &c;

  cout << "Value of boolean: " << a << endl;
  cout << "Value of char: " << b << endl;
  cout << "Value of int: " << c << endl;
  cout << "Value of double: " << d << endl;
  cout << "Value of int pointer: " << e << endl;
  */

  //Next section of PreLab starts here.
  int IntArray[10] = {1,2,3,4,5,6,7,8,9,10};
  char CharArray[10] = {'a','b','c','d','e','f','g','h','i','j'};

  int IntArray2D[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
  char CharArray2D[6][5] = {{'a','b','c','d','e'},{'f','g','h','i','j'},{'h','i','j','k','l'}};


  //Addresses of first spot of each array.
  //0x00007fffffffdfc0 -> 140737488347072
  //0x00007fffffffdfb6 -> 140737488347062
  //0x00007fffffffdf30 -> 140737488346928
  //0x00007fffffffdf10 -> 140737488346896
  
 
  return 0;
}
