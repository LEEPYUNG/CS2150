// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include "vertex.cpp"
using namespace std;

// we want to use parameters
int main(int argc, char** argv) {
  
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s1, s2;
    vector<string> courseList;
    vector<vertex*> vertexes;
    vector<string>::iterator it;
    
    while(1){
      file >> s1;
      file >> s2;

      if(s1 == "0" && s2 == "0"){
	//	cout << "end of list." << endl;
	break;
      }

      //Get all names of the courses and put into courseList vector.
      it = find(courseList.begin(), courseList.end(), s1);
      if(it != courseList.end()){
	//	cout << "class: " << s1 << " found in courselist." << endl;
      }
      else{
	//	cout << "class: " << s1 << " not found. Will be added." << endl;
	courseList.push_back(s1);
      }

      it = find(courseList.begin(), courseList.end(), s2);
      if(it != courseList.end()){
	//	cout << "class: " << s2 << " found in courselist." << endl;
      }
      else{
	//	cout << "class: " << s2 << " not found. Will be added." << endl;
	courseList.push_back(s2);
      }              
    }

    //  cout << "nodes will be made now." << endl;

    //Make vertex pointers for all the courses and put them into a vector.   
    for(int i = 0; i < courseList.size(); i++){
      vertex* course = new vertex(courseList[i]);
      vertexes.push_back(course);
    }

    // cout << "all nodes have been created." << endl;

    //Now there should be vertex node pointers for each class.
  

    //Read the file again.
    file.clear();
    file.seekg(0);

    while(true){
   
      file >> s1;
      file >> s2;

      if(s1 == "0" && s2 == "0"){
	// cout << "end of list." << endl;
	break;
      }

      vertex* temp = nullptr; //current course
      vertex* next = nullptr; //next course

      for(int i = 0; i < vertexes.size(); i++){ //find the pointer for current course
	if(vertexes[i]->getName() == s1){
	  temp = vertexes[i];
	  break;
	}
      }

      for(int i = 0; i < vertexes.size(); i++){ //find the pointer for second course.
	if(vertexes[i]->getName() == s2){
	  next = vertexes[i];
	  break;
	}
      }
      temp->addEdge(next);
    }

       
    // close the file before exiting
    file.close();

    
    vector<string> order;
    vector<vertex*> zero; //Create a vector that has all the vertexes of indegree 0.   
    int count = vertexes.size();

    while(count > 0) {

      
      for(int i = 0; i < vertexes.size(); i++){ //for loop to find which courses have indegree of 0
	if(vertexes[i]->indegree == 0){
	  zero.push_back(vertexes[i]);
	  order.push_back(vertexes[i]->getName());
	  // cout << "Adding: " << vertexes[i]->getName() << " into zero vector and order vector." << endl;	
	}
      }

      for(int i = 0; i< zero.size(); i++){ //Going through zero matrix and decrement edges.     
	zero[i]->subtractEdge();     
      }
      zero.clear();  //Clear zero vector

    count--;
    } //while loop

    //Print the final topological sort.
    for(int i = 0; i < order.size(); i++){
      cout << order[i] << " ";
    }
    cout << endl;

    //Dereference dynamically created memory.
    for(int i = 0; i < vertexes.size(); i++){
      delete vertexes[i];
    }
    
} //main ending closing bracket
