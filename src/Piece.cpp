/** Include */

#include "../include/Piece.h"

/**
 * \brief Implementation of the method for the class Piece.
 */

 /**
  * \brief Empty constructor.
  * Complexity : O(1).
  */
 Piece::Piece() {
    set_piece('.');
 }

/**
 * \brief Constructor of the object Piece.
 * \param board
 * Complexity : O(1).
 */
Piece::Piece(char pawn) {
    set_piece(pawn);
}

/**
 * \brief Operator =.
 * \param pawn
 * \exception IllegalCharException : if the pawn change from '.', 'X' or 'O'.
 * \return the pawn.
 * Complexity : O(1).
 */
void Piece::operator= (char pawn) {
    set_piece(pawn);
}

/**
 * \brief overloading the operator char.
 * \return the good place in the board.
 * Complexity : O(1).
 */
Piece::operator char() const {
    return get_piece();
}

/**
 * \brief Get piece.
 * \return the piece.
 * Complexity : O(1).
 */
char Piece::get_piece() const {
    return piece;
}

/**
 * \brief Set piece.
 * \param pawn.
 * \exception if the char is not good.
 * Complexity : O(1).
 */
void Piece::set_piece(char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    piece = pawn;
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
std::ostream& operator<< (std::ostream& os, Piece& piece) {
    os << piece.get_piece();
    return os;
}
