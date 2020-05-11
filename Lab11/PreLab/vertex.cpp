/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/21/2020
	File Name:vertex.cpp
*/

#include "vertex.h"
#include <string>
using namespace std;

vertex::vertex(string name) {
  indegree = 0;
  courseName = name;
}

vertex::~vertex() {
  //
}

void vertex::increaseIndegree(){
  indegree++;
}

void vertex::decreaseIndegree(){
  indegree--;
}

string vertex::getName(){
  return courseName;
}

void vertex::addEdge(vertex* nextCourse){
  edges.push_back(nextCourse);
  nextCourse->increaseIndegree();
}

void vertex::subtractEdge(){
  indegree = -1;
  for(int i = 0; i < edges.size(); i++){
    edges[i]->decreaseIndegree();
  }
}




			 
