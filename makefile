CURRENT_DIR = $(shell pwd)
CXX = clang++-5.0
CXXFLAGS = -std=c++17
SRC_DIR = $(CURRENT_DIR)/src
HEADERS_DIR = $(CURRENT_DIR)/include

all: Board.o FulfillTheBoard.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o FulfillTheBoard.o IllegalCoordinateException.o IllegalCharException.o
	
Board.o: $(SRC_DIR)/Board.cpp  $(HEADERS_DIR)/Board.h  $(HEADERS_DIR)/FulfillTheBoard.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o
	
FulfillTheBoard.o: $(SRC_DIR)/FulfillTheBoard.cpp  $(HEADERS_DIR)/FulfillTheBoard.h $(HEADERS_DIR)/Board.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FulfillTheBoard.cpp -o FulfillTheBoard.o
	
IllegalCoordinateException.o: $(SRC_DIR)/IllegalCoordinateException.cpp  $(HEADERS_DIR)/IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: $(SRC_DIR)/IllegalCharException.cpp  $(HEADERS_DIR)/IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCharException.cpp -o IllegalCharException.o

clean:
	rm *.o a.out
