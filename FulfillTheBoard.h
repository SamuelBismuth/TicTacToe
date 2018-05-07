#ifndef FULFILLTHEBOARD_H
#define FULFILLTHEBOARD_H

/** Includes */

#include <iostream>

#include "IllegalCharException.h"
#include "Board.h"

class Board;

using namespace std;

/**
 * \brief This class fulfill the Board.
 * \author Johann and Samuel.
 */
class FulfillTheBoard {

    public:

        //Constructor.

        FulfillTheBoard(int x, int y, Board* board);

        //Operators

        char operator= (char pawn);
        operator char();

    protected:

    private:

        //Variables of the object.

        int x,
            y;
        Board* board;

        // Operator << to print the Board.

        friend ostream& operator<< (ostream& os, const FulfillTheBoard& fulfillTheBoard);
};

#endif // FULFILLTHEBOARD_H
