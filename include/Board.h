#ifndef BOARD_H
#define BOARD_H

/** Includes */

#include <iostream>
#include <vector> // For the vector use.

#include "Piece.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

// This allow to use the class FulfillTheBoard in the class Board and
// use the class Board in the class FulfillTheBoard too.

using namespace std;

/**
 * \brief This class is a Board.
 * This board is the base of the game connection 4.
 * \author Johann and Samuel.
 */
class Board {

    public:

        //Constructors

        Board(const Board& board);        //Copy constructor.
        Board(size_t dimension);    //Constructor. TODO: const

        //D_tor

        ~Board();

        //Operators

        Piece& operator[] (vector<int> point);
        Board& operator= (char pawn);
        Board& operator= (const Board& board);

        //Getters.

        size_t getDimension() const;

    protected:

    private:

        // Variables of the object Board.

        size_t dimension;
        Piece** matrix;

        //help function.

        void fill(char pawn);

        // Operator << to print the Board.

        friend ostream& operator<< (ostream& os, const Board& board);
};

#endif // BOARD_H
