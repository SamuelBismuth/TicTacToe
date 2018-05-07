/** Include */

#include "Piece.h"

/**
 * \brief Implementation of the method for the class FulfillTheBoard.
 */

 Piece::Piece() {
    this->piece = '.';
 }

/**
 * \brief Constructor of the object FulfillTheBoard.
 * \param x
 * \param y
 * \param board
 */
Piece::Piece(char pawn) {
    this->piece = pawn;
}

/**
 * \brief Operator =.
 * \param pawn
 * \exception IllegalCharException : if the pawn change from '.', 'X' or 'O'.
 * \return the pawn.
 */
char Piece::operator= (char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    piece = pawn;
    return pawn;
}

/**
 * \brief overloading the operator char.
 * \return the good place in the board.
 */
Piece::operator char() const {
    return piece;
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
ostream& operator<< (ostream& os, const Piece& piece) {
    os << piece.piece;
    return os;
}


