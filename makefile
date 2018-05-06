CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: main.o Board.o FulfillTheBoard.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o FulfillTheBoard.o IllegalCoordinateException.o IllegalCharException.o  main.o
	./a.out

Board.o: Board.cpp Board.h FulfillTheBoard.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	
FulfillTheBoard.o: FulfillTheBoard.cpp FulfillTheBoard.h Board.h
	$(CXX) $(CXXFLAGS) -c FulfillTheBoard.cpp -o FulfillTheBoard.o
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

main.o: main.cpp Board.h FulfillTheBoard.h IllegalCoordinateException.h IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
