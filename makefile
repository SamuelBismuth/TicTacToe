CURRENT_DIR = $(shell pwd)
CXX = clang++-5.0
CXXFLAGS = -std=c++17

all: Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o
	
Board.o: Board.cpp Board.h Piece.h 
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	
Piece.o: Piece.cpp  Piece.h Board.h
	$(CXX) $(CXXFLAGS) -c Piece.cpp -o Piece.o
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

clean:
	rm *.o a.out
