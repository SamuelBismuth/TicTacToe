#ifndef BOARD_H
#define BOARD_H

/** Includes */

#include <iostream>
#include <vector> // For the vector use (which replaces coordinate).

#include "Piece.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

/**
 * \brief This class is a Board.
 * This board is the base of the game connection 4.
 * \author Johann and Samuel.
 */
class Board {

    public:

        //Constructors

        Board();
        Board(const Board& board);        //Copy constructor.
        Board(std::size_t dimension);    //Constructor. TODO: const

        //D_tor

        ~Board();

        //Operators

        Piece& operator[] (std::vector<std::size_t> point) const;
        Board& operator= (char pawn);
        Board& operator= (const Board& board);

        //size

        size_t size() const;

        //Getter.

        size_t getDimension() const;

        //Setter

        void setBoard(const std::size_t dimension);
        void setDimension(const std::size_t dimension);
        void setMatrix(const std::size_t dimension);

    private:

        // Variables of the object Board.

        std::size_t dimension;
        Piece** matrix;

        //help function.

        void fill(char pawn);

        // Operator << to print the Board.

        friend std::ostream& operator<< (std::ostream& os, const Board& board);
};

#endif // BOARD_H
