#ifndef FULFILLTHEBOARD_H
#define FULFILLTHEBOARD_H

/** Includes */

#include <iostream>

#include "IllegalCharException.h"

/**
 * \brief This class represents a piece of the game.
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

    private:

        //Variables of the object.

        char piece;

        // Operator << to print the Board.

        friend std::ostream& operator<< (std::ostream& os, Piece& piece);
};

#endif // FULFILLTHEBOARD_H
