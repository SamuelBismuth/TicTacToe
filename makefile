CXX = clang++-5.0
CXXFLAGS = -std=c++17

all: Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o
	
Board.o: Board.cpp Board.h Piece.h 
	
Piece.o: Piece.cpp  Piece.h Board.h
	
IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.h
	
IllegalCharException.o: IllegalCharException.cpp IllegalCharException.h

clean:
	rm *.o

