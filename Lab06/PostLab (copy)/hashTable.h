/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 3/3/2020
	File Name: hashTable.h
*/
// hashTable.h
// CS 2150: Lab 6


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
using namespace std;

class HashTable {
public:
    HashTable();                     // Constructor
    //~HashTable();
    int hashFunction(string word);  // Deletes tree/frees memory
    void insert(string word);       // Gets data from user
    bool find(string word);         // Puts value in tree
   
    vector<string> h1;


};

#endif
