#ifndef FULFILLTHEBOARD_H
#define FULFILLTHEBOARD_H

#include <iostream>

#include "Board.h"

using namespace std;

class FulfillTheBoard {
    public:
        FulfillTheBoard(int x, int y, Board* board);
        char& operator= (char pawn);

    protected:

    private:
        int x,
            y;
        Board* board;
};

#endif // FULFILLTHEBOARD_H
