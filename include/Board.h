#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

class FulfillTheBoard;

using namespace std;

class Board {
    public:
        Board(const Board& board);
        Board(const size_t dimension);
        FulfillTheBoard operator[] (vector<int> point);
        Board& operator= (char pawn);
        //Board& operator= (Board& board);
        void changePawn(char pawn, int x, int y);

    protected:

    private:
        char** matrix;
        size_t dimension;
        friend ostream& operator<< (ostream& os, const Board& board);
};

#endif // BOARD_H
