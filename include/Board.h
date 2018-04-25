#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "IllegalCoordinateException.h"

using namespace std;

class Board {
    public:
        Board(const size_t dimension);
        char& operator[] (vector<int> point);

    protected:

    private:
        char** matrix;
        size_t dimension;
        friend ostream& operator<< (ostream& os, const Board& board);
};

#endif // BOARD_H
