/** Include */

#include "IllegalCoordinateException.h"

/**
 * \brief Implementation of the method for the class IllegalCoordinateException.
 */

/**
 * \brief Constructor for the exception.
 * \param pawn
 */
IllegalCoordinateException::IllegalCoordinateException(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 * \brief get the wrong coordinate.
 * \return a string which contains the wrong coordinate.
 */
std::string IllegalCoordinateException::theCoordinate() const {
    return std::to_string(x) + "," + std::to_string(y);
}

