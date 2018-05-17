#ifndef ILLEGALCHAREXCEPTION_H
#define ILLEGALCHAREXCEPTION_H

/** Includes */

#include <iostream>
#include <exception>
#include <string>

/**
 * \brief This exception class controls if the char are the good one.
 * \author Johann and Samuel.
 */
class IllegalCharException : public std::exception {

    public:

        //Constructor.

        IllegalCharException(char pawn);

        // Function for the error.

        char theChar() const;

    private:

        //Variable of the exception.

        char pawn;
};

#endif // ILLEGALCHAREXCEPTION_H
