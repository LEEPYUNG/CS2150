

/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/15/2020
	File Name: huffmanNode.h
*/

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
using namespace std;

class huffmanNode {
public:
    huffmanNode(char c, int freq);
    ~huffmanNode();

    char character;
    int	 frequency;
    string prefix;
    huffmanNode* left;
    huffmanNode* right;

    int getFrequency();
    string getPreFix();
    	

};

#endif
