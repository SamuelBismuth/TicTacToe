CURRENT_DIR = $(shell pwd)
CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = $(CURRENT_DIR)
HEADERS_DIR = $(CURRENT_DIR)

all: main.o Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o 
	$(CXX) $(CXXFLAGS) Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o main.o 
	./a.out < board3.txt
	./a.out < board6.txt
	xdg-open board.ppm
	xdg-open board2.ppm

Board.o: $(SRC_DIR)/Board.cpp $(HEADERS_DIR)/Board.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o
	
Piece.o: $(SRC_DIR)/Piece.cpp $(HEADERS_DIR)/Piece.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Piece.cpp -o Piece.o
	
IllegalCoordinateException.o: $(SRC_DIR)/IllegalCoordinateException.cpp $(HEADERS_DIR)/IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: $(SRC_DIR)/IllegalCharException.cpp $(HEADERS_DIR)/IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCharException.cpp -o IllegalCharException.o

main.o: main.cpp $(HEADERS_DIR)/Board.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out board.ppm board2.ppm
