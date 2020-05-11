/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/16/2020
	File Name: heap.h
*/

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H
#include "huffmanNode.h"
#include <vector>
#include <string>
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffmanNode*> vec);
    ~heap();

    void insert(huffmanNode* x);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void findPreFix(string x, huffmanNode* cur);


    vector<huffmanNode*> minHeap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
