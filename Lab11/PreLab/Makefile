# This is a comment
#Name: Pyung Lee
#pkl4fr
#Lab Section: 106 (15764)

CXX=clang++ $(CXXFLAGS)	
CXXFLAGS=-Wall -O2 -g # Enable all warnings
DEBUG=-g
OBJECTS =  topological.o

main:   $(OBJECTS)
	$(CXX)  $(DEBUG) $(OBJECTS) -o a.out
	doxygen -g


clean: -rm -f *.o *~ fileio2

vertex.o: vertex.cpp vertex.h
	$(CXX) -O2 -c vertex.cpp


