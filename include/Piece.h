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

        void operator= (char pawn);
        operator char() const;

        //Getter

        char get_piece() const;

        //Setter

        void set_piece(char pawn);


    protected:

    private:

        //Variables of the object.

        char piece;

        // Operator << to print the Board.

        friend ostream& operator<< (ostream& os, Piece& piece);
};

#endif // FULFILLTHEBOARD_H
