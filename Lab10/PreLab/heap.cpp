/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/16/2020
	File Name:heap.cpp
*/

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <string>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// 0default constructor
heap::heap() : heap_size(0) {
    minHeap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    minHeap = vec;
    minHeap.push_back(minHeap[0]);
    minHeap[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    minHeap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = minHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < minHeap[hole/2]->frequency); hole /= 2 )
        minHeap[hole] = minHeap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    minHeap[hole] = x;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffmanNode* ret = minHeap[1];
    // move the last inserted position into the root
    minHeap[1] = minHeap[heap_size--];
    // make sure the vector knows that there is one less element
    minHeap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = minHeap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) { //while we are not a leaf...
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (minHeap[child+1]->frequency < minHeap[child]->frequency) )
	  child++; //child is now the right child.
        // if the child is greater than the node...
        if ( x->frequency > minHeap[child]->frequency ) {
            minHeap[hole] = minHeap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    minHeap[hole] = x;
}

huffmanNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return minHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    minHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << minHeap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << minHeap[i]->character << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}

void heap::findPreFix(string x, huffmanNode* curNode){
  if(curNode->left == NULL && curNode->right == NULL){
    curNode->prefix = x;
  }
  else{
    string leftStr = "0"+x;
    string rightStr = "1"+x;
    findPreFix(leftStr, curNode->left);
    findPreFix(rightStr, curNode->right);
  }
}
