CURRENT_DIR = $(shell pwd)
CXX = clang++-5.0
CXXFLAGS = -std=c++17
SRC_DIR = $(CURRENT_DIR)/src
HEADERS_DIR = $(CURRENT_DIR)/include

<<<<<<< HEAD
all: main.o Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o main.o
	./a.out

main.o: $(CURRENT_DIR)/main.cpp $(HEADERS_DIR)/Board.h $(HEADERS_DIR)/Piece.h
	$(CXX) $(CXXFLAGS) -c $(CURRENT_DIR)/main.cpp -o main.o
	
=======
all: Board.o Piece.o IllegalCharException.o IllegalCoordinateException.o
	$(CXX) $(CXXFLAGS) Board.o Piece.o IllegalCoordinateException.o IllegalCharException.o

>>>>>>> 83705d724b18c95cb1e343283b7375353770cd64
Board.o: $(SRC_DIR)/Board.cpp $(HEADERS_DIR)/Board.h $(HEADERS_DIR)/Piece.h 
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Board.cpp -o Board.o
	
Piece.o: $(SRC_DIR)/Piece.cpp $(HEADERS_DIR)/Piece.h $(HEADERS_DIR)/Board.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Piece.cpp -o Piece.o
	
IllegalCoordinateException.o: $(SRC_DIR)/IllegalCoordinateException.cpp $(HEADERS_DIR)/IllegalCoordinateException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCoordinateException.cpp -o IllegalCoordinateException.o
	
IllegalCharException.o: $(SRC_DIR)/IllegalCharException.cpp $(HEADERS_DIR)/IllegalCharException.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/IllegalCharException.cpp -o IllegalCharException.o

clean:
	rm *.o a.out
