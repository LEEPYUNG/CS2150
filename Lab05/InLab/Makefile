# This is a comment
#Name: Pyung Lee
#pkl4fr
#Lab Section: 106 (15764)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
DEBUG=-g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o 

BSTPathTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done Compiling"

clean: -rm -f *.o *~ BSTPathTest


BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp  BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp 
	$(CXX) -c BSTPathTest.cpp


