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
char FulfillTheBoard::operator= (const char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    board->setPawn(pawn, x, y);
    return pawn;
}

/**
 * \brief overloading the operator char.
 * \return the good place in the board.
 */
FulfillTheBoard::operator char() {
    return board->getMatrix()[x][y];
}

bool FulfillTheBoard::operator== (char const& pawn) {
    if (board->getMatrix()[x][y] == pawn)
	return true;
    return false;
}

//privates methods.

//friends operators.

/**
 * \brief This friend operator prints the board. (As toString in Java).
 * \param os
 * \param board
 * \return os.
 * Complexity : O(1).
 */
ostream& operator<< (ostream& os, FulfillTheBoard& fulfillTheBoard) {
    os << fulfillTheBoard.board->getMatrix()[fulfillTheBoard.x][fulfillTheBoard.y] << endl;
    return os;
}


