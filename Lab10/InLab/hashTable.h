/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/15/2020
	File Name: hashTable.h
*/
// hashTable.h
// CS 2150: Lab 10


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include "huffmanNode.h"
using namespace std;

class HashTable {
public:
    HashTable();                // Constructeor
    int hashFunction(char c);   // Deletes tree/frees memory
    void insert(char c);        // inserts data into table.
    bool find(char c);          // Puts value in tree
    int getValue(char c); 	//Gets the value in index.
    huffmanNode* getNodePointer(char c); //gets the pointer  
    vector<huffmanNode*> myHashTable;


};

#endif
