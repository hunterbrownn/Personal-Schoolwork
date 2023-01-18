#Hunter Brown, ghb6mt, 3/14/22



CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

wordPuzzle: wordPuzzle.o timer.o hashTable.o
	$(CXX) $(DEBUG) hashTable.o wordPuzzle.o timer.o

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
#timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
