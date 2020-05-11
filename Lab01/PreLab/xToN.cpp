/*
  Name: Pyung Lee
  Email ID: pkl4fr
  Date: 1/18/20
  FIle Name: xToN.cpp
 */

#include <iostream>
using namespace std;

int xton(int num, int power){
  return (power == 0) ? 1 :num * xton(num, power-1); 
}

int main(){
  int num, power, ans;
  cin >> num;
  cin >> power;

  ans = xton(num,power);
  cout << num << " to the power of " << power << " is: " << ans << endl;
  return 0;
}
