/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/17/2020
	File Name: huffmandec.cpp
*/


// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include "hashTable.cpp"
#include "huffmanNode.cpp"
#include "heap.cpp"
#include <bits/stdc++.h> //to convert from string to char array
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    heap myHeap;
    huffmanNode* root = new huffmanNode('-',0);

    
    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;


	int n = character.length();
	char arr[n+1];
	strcpy(arr,character.c_str());
	//*****************************
	char symbol = arr[0];	
	huffmanNode* node = new huffmanNode(symbol, 1);
       	
	
	//Adding the new character to root node.
	  string prefixCode = prefix;
	  huffmanNode* curNode = root;

	  for(int i = 0; i < prefixCode.length(); i++){
	    char  dir = prefixCode[i];
	    
	    if(dir == '1'){ //Right	      
	      if(curNode->right == NULL && i == prefixCode.length()-1){ //The right node is not empty.	
		curNode->right = node;
		//	cout << "The node with character " << character << " added to right." << endl;
	      }
	      
	      else{ //Set curnode to that node, look again.
		if(curNode->right == NULL) {
		  //	  cout << "Cheecking Right..there was nothing here...creating dummy node" << endl;
		  huffmanNode* dummy = new huffmanNode('-', 0);
		  curNode->right = dummy;
		}
		curNode = curNode->right;
		//	cout << "It was moved right." << endl;
	      }
	      
	    } 
	    else{ //Left
	      if(curNode->left == NULL && i == prefixCode.length()-1){ //The right node is not empty.
		curNode->left = node;
		//	cout << "The node with character " << character << " added to left." << endl;
	      }
	      else{ //Set curnode to that node, look again.
		if(curNode->left == NULL) {
		  //  cout << "Checking Left...there was nothing here...creating dummy node" << endl;
		  huffmanNode* dummy = new huffmanNode('-', 0);
		  curNode->left = dummy;
		}
		curNode = curNode->left;
		//	cout << "It was moved left." << endl;
	      }

	    }
	      
	  }
	 

	  //At this point, all the nodes should have been added to the root.
	  cout << "all nodes added."<<endl;

	  //ADding Root into heap.
	  myHeap.insert(root);
    }
    

    // read in the second section of the file: the encoded message

   
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    cout << endl;


    huffmanNode* curNode = root;
    for(int i = 0; i < allbits.length(); i++){
      char bit = allbits[i];

      if(bit == '1'){
	curNode = curNode->right;
	if(curNode->left == NULL && curNode->right == NULL){
	  cout << curNode->character;
	  curNode = root;
	}
      }
      else{
	curNode = curNode->left;
	if(curNode->left == NULL && curNode->right == NULL){
	  cout << curNode->character;
	  curNode = root;
	}
      }  
    }

    delete root;
    cout<<endl;
    
}
