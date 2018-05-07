#ifndef BOARD_H
#define BOARD_H

/** Includes */

#include <iostream>
#include <vector> // For the vector use.

#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include "FulfillTheBoard.h"

// This allow to use the class FulfillTheBoard in the class Board and
// use the class Board in the class FulfillTheBoard too.

class FulfillTheBoard;

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
        Board(const size_t dimension);    //Constructor.

        //D_tor

        ~Board();

        //Operators

        FulfillTheBoard operator[] (vector<int> point);
        Board& operator= (char pawn);
        Board& operator= (Board& board);

        //Setter

        void setPawn(char pawn, int x, int y);

        //Getters.

        char** getMatrix();
        size_t getDimension();

    protected:

    private:

        // Variables of the object Board.

        char** matrix;
        size_t dimension;

        // Operator << to print the Board.

        friend ostream& operator<< (ostream& os, const Board& board);
};

#endif // BOARD_H
