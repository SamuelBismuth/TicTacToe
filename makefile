CURRENT_DIR = $(shell pwd)
CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = $(CURRENT_DIR)/src
HEADERS_DIR = $(CURRENT_DIR)/include

all: Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o Champion.o DummyPlayers.o TicTacToe.o Player.o 
	$(CXX) $(CXXFLAGS) Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o Champion.o DummyPlayers.o TicTacToe.o Player.o

Board.o: $(SRC_DIR)/Board.cpp $(HEADERS_DIR)/Board.h  
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o
	
Piece.o: $(SRC_DIR)/Piece.cpp $(HEADERS_DIR)/Piece.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Piece.cpp -o Piece.o
	
IllegalCoordinateException.o: $(SRC_DIR)/IllegalCoordinateException.cpp $(HEADERS_DIR)/IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: $(SRC_DIR)/IllegalCharException.cpp $(HEADERS_DIR)/IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCharException.cpp -o IllegalCharException.o

Champion.o: $(SRC_DIR)/Champion.cpp $(HEADERS_DIR)/Champion.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Champion.cpp -o Champion.o

DummyPlayers.o: $(SRC_DIR)/DummyPlayers.cpp $(HEADERS_DIR)/DummyPlayers.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/DummyPlayers.cpp -o DummyPlayers.o

TicTacToe.o:$(SRC_DIR)/TicTacToe.cpp $(HEADERS_DIR)/TicTacToe.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/TicTacToe.cpp -o TicTacToe.o

Player.o:$(SRC_DIR)/Player.cpp $(HEADERS_DIR)/Player.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Player.cpp -o Player.o

#main.o: main.cpp $(HEADERS_DIR)/TicTacToe.h $(HEADERS_DIR)/DummyPlayers.h $(HEADERS_DIR)/Champion.h
#	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
