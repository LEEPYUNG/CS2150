/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/14/2020
	File Name: bitcounter.cpp
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int bitcounter(int n){
  if ( n  == 0 ) {
    return 0;
  }
  else if( n == 1 ){
    return 1;
  }
  else if(n%2 == 0 && n != 0){    
    return bitcounter(n/2);
  }
  else if(n%2 != 0 && n != 1){
    return 1 + bitcounter(floor(n/2)); 
  }

}

int main(int argc, char **argv){

  if(argc != 2){
    cout << "No input found for bitcounter function." << endl;
  }
  else {
  
    int x = atoi(argv[1]);
    int ans = bitcounter(x);
    cout << ans << endl;

  }
  
  return 0;
}
