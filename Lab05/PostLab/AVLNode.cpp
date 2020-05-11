/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:2/26/2020
	File Name: AVLNode.cpp
*/

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
