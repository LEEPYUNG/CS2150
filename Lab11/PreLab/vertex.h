

/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/21/2020
	File Name: vertex.h
*/

#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>
using namespace std;

class vertex {
public:
	/**
	*Vertex Constructor
	*Constructs a vertex object given an string name as a parameter.
	*
	*@param name A string name for the vertex.
	*/
	vertex(string name);

	/**
	*Vertex Destructor
	*Deletes the vertex object.
	*
	*/
	~vertex();

	/**
	*A public variable.
	*Holds the number of edges going into this vertex.
	*/
	int indegree;	

	/**
	*A public variable.
	*Holds the courseName of this vertex.
	*/		
	string courseName;		
	
	/**
	*Increases the indegree field of the object specified by 1.
	*@return returns void.
	*/
	void increaseIndegree();
	
	/**
	*Decreses the indegree field of the object specified by 1.
	*@return returns void
	*/	
	void decreaseIndegree();   

	/**
	*Given a specified vertex object, returns its coursename field.
	*@return returns a string, the courseName field.
	*/		
	string getName();	
	
	/**
	*A public variable.
	*Holds a vector of vertex pointers representing which other courses this class leads to.
	*/	
	vector<vertex*> edges;		

	/**
	*Adds the nextCourse pointer to this vertex's edges vector. Increases nextCourse's indegree by 1
	*@param nextCourse A vertex pointer to the class this vertex leads to.
	*@return returns void
	*/
	void addEdge(vertex* nextCourse);  

	/**
	*Goes through the edges vector of this vertex and decreases the indegree 
	*of all of the vertexes in that vector by 1. Also sets this vertex's indegree to -1. 
	*@return returns void
	*/
	void subtractEdge();		
};

#endif
