// mathfun.cpp

/*
Pyung Lee
PKL4FR
3/31/20

 */



#include <iostream>

using namespace std;

extern "C" long product(long, long);

// Purpose: This main program produces a returns the product of two parameters
int  main () {
    // delcare the local variables
    long  a,b, answerProduct;

    // how big is the array we want to use?
    cout << "Please enter a number:  ";
    cin >> a;
    cout << "Please enter another number:  ";
    cin >> b;

    // find product  and print out results
    answerProduct = product(a,b);
    cout << "The product of the numbers  is " << answerProduct << endl;

    // all done!
    return 0;
}
