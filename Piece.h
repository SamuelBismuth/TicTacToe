#ifndef FULFILLTHEBOARD_H
#define FULFILLTHEBOARD_H

/** Includes */

#include <iostream>

#include "IllegalCharException.h"

using namespace std;

/**
 * \brief This class fulfill the Board.
 * \author Johann and Samuel.
 */
class Piece {

    public:

        //Constructors.

        Piece();
        Piece(char pawn);

        //Operators

        char operator= (char pawn);
        operator char() const;

    protected:

    private:

        //Variables of the object.

        char piece;

        // Operator << to print the Board.

        friend ostream& operator<< (ostream& os, const Piece& piece);
};

#endif // FULFILLTHEBOARD_H
