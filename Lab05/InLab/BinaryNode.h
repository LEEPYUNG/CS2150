/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 2/25/2020
	File Name: BinaryNode.h
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
