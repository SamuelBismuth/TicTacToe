#ifndef ILLEGALCHAREXCEPTION_H
#define ILLEGALCHAREXCEPTION_H

/** Includes */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/**
 * \brief This exception class controls if the char are the good one.
 * \author Johann and Samuel.
 */
class IllegalCharException : public exception {

    public:

        //Constructor.

        IllegalCharException(char pawn);

        // Function for the error.

        char theChar() const;

    protected:

    private:

        //Variable of the exception.

        char pawn;
};

#endif // ILLEGALCHAREXCEPTION_H
