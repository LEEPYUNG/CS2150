# This is a comment
#Name: Pyung Lee
#pkl4fr
#Lab Section: 106 (15764)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
DEBUG=-g
OBJECTS =  huffmanenc.o 

wordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

clean: -rm -f *.o *~ huffmanenc

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -O2 -c hashTable.cpp

wordPuzzle.o:huffmanenc.cpp 
	$(CXX) -O2 -c huffmanenc.cpp

huffmanNode.o:huffmanNode.cpp huffmanNode.h
	$(CXX) -O2 -c huffmanNode.cpp

heap.o: heap.cpp heap.h
	$(CXX) -O2 -c heap.cpp



