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

        //Operators

        char operator= (char pawn);
        operator char();
        bool operator== (const char& pawn) const;

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
