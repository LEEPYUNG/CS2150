# This is a comment
#Name: Pyung Lee
#pkl4fr
#Lab Section: 106 (15764)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
DEBUG=-g
OBJECTS = AVLNode.o AVLTree.o AVLPathTest.o 

AVLPathTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done Compiling"

clean: -rm -f *.o *~ AVLPathTest


AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	$(CXX) -c AVLTree.cpp

AVLPathTest.o: AVLPathTest.cpp 
	$(CXX) -c AVLPathTest.cpp


