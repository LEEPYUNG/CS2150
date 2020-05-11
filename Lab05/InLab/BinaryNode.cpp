/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 2/25/2020
	File Name: BinaryNode.cpp
*/

#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
