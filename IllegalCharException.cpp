/** Include */

#include "../include/IllegalCharException.h"

/**
 * \brief Implementation of the method for the class IllegalCharException.
 */

/**
 * \brief Constructor for the exception.
 * \param pawn
 */
IllegalCharException::IllegalCharException(char pawn) {
    this->pawn = pawn;
}

/**
 * \brief get the wrong char.
 * \return the wrong char.
 */
char IllegalCharException::theChar() const {
    return pawn;
}



