# This is a comment
#Name: Pyung Lee
#pkl4fr
#Lab Section: 106 (15764)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings
DEBUG=-g
OBJECTS =  wordPuzzle.o 

wordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Done Compiling"

clean: -rm -f *.o *~ wordPuzzle

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -O2 -c hashTable.cpp

timer.o: timer.cpp  timer.h
	$(CXX) -O2 -c timer.cpp

wordPuzzle.o:wordPuzzle.cpp 
	$(CXX) -O2 -c wordPuzzle.cpp


