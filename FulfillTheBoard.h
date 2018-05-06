#ifndef FULFILLTHEBOARD_H
#define FULFILLTHEBOARD_H

/** Includes */

#include <iostream>

// This allow to use the class FulfillTheBoard in the class Board and
// use the class Board in the class FulfillTheBoard too.

#include "Board.h"

using namespace std;

/**
 * \brief This class fulfill the Board.
 * \author Johann and Samuel.
 */
class FulfillTheBoard {

    public:

        //Constructor.

        FulfillTheBoard(int x, int y, Board* board);

        //Operator

        char& operator= (char pawn);

    protected:

    private:

        //Variables of the object.

        int x,
            y;
        Board* board;
};

#endif // FULFILLTHEBOARD_H
