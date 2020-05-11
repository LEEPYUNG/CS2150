/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/15/2020
	File Name: huffmanNode.cpp
*/

#include "huffmanNode.h"
#include <string>
using namespace std;

huffmanNode::huffmanNode(char c, int freq) {
    frequency = freq;
    character = c;
    prefix  = "";
    left = NULL;
    right = NULL;
}

huffmanNode::~huffmanNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}

int huffmanNode::getFrequency(){
  return frequency;
}

string huffmanNode::getPreFix(){
  return prefix;
}


			 
