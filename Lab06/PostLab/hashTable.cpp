/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 3/3/2020
	File Name: hashTable.cpp
*/

#include "hashTable.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

HashTable::HashTable(){
  h1 = vector<string>(37571);
  //collisions = 0;
}


int HashTable::hashFunction(string word) {
  int sum = 0;
  for(int i = 0; i < word.length(); i++){
    sum = 37*sum + (int(word[i]) * (37^i));
  }
  
  return sum % 37571;
}


void HashTable::insert(string word) { //linear probing
  //cout << "NEW INSERT!" << endl;
  
  int index = hashFunction(word);
  int count = 1;


  if(!find(word) && h1[index] == ""){
    h1[index] = word;

    cout << "WORD INPUTTED" << endl;
  }
  else {
    //cout << "COLLIDED!" << endl;
    //collisions = collisions + 1;
    while(true){
      if(h1[index + count] == ""){
	h1[index + count] = word;
	//	cout << "WORD INPUTTED" << endl;
	break;
      }
      count++;
    }
  }
}


bool HashTable::find(string word){
  int index = hashFunction(word);
  
  while(index < h1.size()){
    if(h1[index] == word){
      return true;
    }
    
    if(index < h1.size()) {
    index++;
    }
    else {
      index = 0;
    }


  
  }

    

      
  return false;
    
 
}

