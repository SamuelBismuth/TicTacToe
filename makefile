CURRENT_DIR = $(shell pwd)
CXX = clang++-5.0
CXXFLAGS = -std=c++17
#DOT := $(doxygen main.cpp Board.cpp Board.h FulfillTheBoard.cpp FulfillTheBoard.h IllegalCoordinateException.cpp IllegalCoordinateException.h IllegalCharException.cpp IllegalCharException.h -v dot 2> /dev/null)
SRC_DIR = $(CURRENT_DIR)/src
HEADERS_DIR = $(CURRENT_DIR)/include

all: main.o Board.o FulfillTheBoard.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o FulfillTheBoard.o IllegalCoordinateException.o IllegalCharException.o main.o
	#ifndef DOT
		#sudo apt install doxygen
	#endif
		#doxygen main.cpp Board.cpp Board.h FulfillTheBoard.cpp FulfillTheBoard.h IllegalCoordinateException.cpp IllegalCoordinateException.h IllegalCharException.cpp IllegalCharException.h
	./a.out
	
Board.o: $(SRC_DIR)/Board.cpp  $(HEADERS_DIR)/Board.h  $(HEADERS_DIR)/FulfillTheBoard.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o
	
FulfillTheBoard.o: $(SRC_DIR)/FulfillTheBoard.cpp  $(HEADERS_DIR)/FulfillTheBoard.h $(HEADERS_DIR)/Board.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/FulfillTheBoard.cpp -o FulfillTheBoard.o
	
IllegalCoordinateException.o: $(SRC_DIR)/IllegalCoordinateException.cpp  $(HEADERS_DIR)/IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: $(SRC_DIR)/IllegalCharException.cpp  $(HEADERS_DIR)/IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCharException.cpp -o IllegalCharException.o

main.o: $(CURRENT_DIR)/main.cpp $(HEADERS_DIR)/Board.h $(HEADERS_DIR)/FulfillTheBoard.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
