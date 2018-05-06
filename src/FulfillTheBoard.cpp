/** Include */

#include "FulfillTheBoard.h"

/**
 * \brief Implementation of the method for the class FulfillTheBoard.
 */

/**
 * \brief Constructor of the object FulfillTheBoard.
 * \param x
 * \param y
 * \param board
 */
FulfillTheBoard::FulfillTheBoard(int x, int y, Board* board) {
    this->x = x;
    this->y = y;
    this->board = board;
}

/**
 * \brief Operator =.
 * \param pawn
 * \exception IllegalCharException : if the pawn change from '.', 'X' or 'O'.
 * \return the pawn.
 */
char& FulfillTheBoard::operator= (char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    board->setPawn(pawn, x, y);
    return pawn;
}


