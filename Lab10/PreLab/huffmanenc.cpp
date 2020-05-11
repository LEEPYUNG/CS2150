/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/16/2020
	File Name:huffmanenc.cpp
*/

#include "hashTable.cpp"
#include "huffmanNode.cpp"
#include "heap.cpp"


#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

  // cout << "testing" << endl;
  HashTable myHash;   //First Hash to hold frequencies
  heap myHeap;       //Create a heap.
  

   // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)

    
    //Fill out Hashtable
    char g;
    vector<char> charactersList; //Holds all the character lists in file
    
    
    while (file.get(g) && (g <= '~' && g >= ' ')) {
      
      if(myHash.find(g) == false){
	 charactersList.push_back(g);
		myHash.insert(g);
      }
      else {
		myHash.insert(g);
      }
    }
    


   

    //Adding the huffman pointers to the minHeap
    int count = 0; //Keep track of how many nodes that are added in.
    for(int i = 0; i < charactersList.size(); i++){    
      huffmanNode* temp =  myHash.getNodePointer(charactersList[i]);
      count++;
      // cout << "inserting node w/ Value: " << temp->character << " and Frequency: " << temp->frequency << "." << endl; 
      myHeap.insert(temp);
    }
	
      //myHeap.print();
      //for(int i = 1; i <= myHeap.size(); i++){
	//	cout << myHeap.minHeap[i]->character << " " << endl;
	//  }
      

	//Now we are going build the tree.
	for(int i = 1; i < count; i++){
	  huffmanNode* temp1 = myHeap.deleteMin();
	  //  cout << "the character1 is: " << temp1->character << endl;
	  huffmanNode* temp2 = myHeap.deleteMin();
	  // cout << "the character2 is: " << temp2->character << endl;						      
	  int totalFreq = (temp1->frequency) + (temp2->frequency);
	  huffmanNode* dummy = new huffmanNode('T', totalFreq);
	  dummy->right = temp1;
	  dummy->left = temp2;
	  myHeap.insert(dummy);
	}

      //Now the Tree should be created.
      //cout << myHeap.minHeap[1]->frequency << endl;


            //Get prefixes
	    myHeap.findPreFix("", myHeap.minHeap[1]);
	  
	 


      for(int i = 0; i < charactersList.size(); i++){
      huffmanNode* temp = myHash.getNodePointer(charactersList[i]);
      cout << temp->character << " " << temp->prefix << endl;
      }
    
    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
	

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    double totalSymbols = 0;
    double compressedBits = 0;
     while (file.get(g) && (g <= '~' && g >= ' ')) {
       huffmanNode* temp = myHash.getNodePointer(g);
       cout << temp->prefix << " ";
       totalSymbols++;

       compressedBits += (temp->prefix).length();
       
      }
     cout << endl;

     cout << "----------------------------------------" << endl;

    
    // close the file
    file.close();


    
    double distinctSymbols = charactersList.size();
    double originalBits = totalSymbols*8;
    double  compressionRatio = originalBits/compressedBits;
    
    //Calulating Cost
    double  cost = 0;
     for(int i = 0; i < charactersList.size(); i++){
       huffmanNode* temp = myHash.getNodePointer(charactersList[i]);
       cost += ((temp->frequency)/(totalSymbols)) * (temp->prefix).length(); 
      }

     cout << "There are a total of " << totalSymbols << " symbols that are encoded." << endl;
     cout << "There are " << distinctSymbols << " distinct symbols used." << endl;
     cout << "There were " << originalBits << " in the original file." << endl;
     cout << "There were " << compressedBits << " in the compressed file." << endl;
     cout << "This gives a compression ratio of " << compressionRatio << "." << endl;
     cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;


     
    return 0;
}





