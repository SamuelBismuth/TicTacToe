#ifndef ILLEGALCOORDINATEEXCEPTION_H
#define ILLEGALCOORDINATEEXCEPTION_H

/** Includes */

#include <iostream>
#include <exception>
#include <string>

/**
 * \brief This exception class controls if the char are the good one.
 * \author Johann and Samuel.
 */
class IllegalCoordinateException : public std::exception {

    public:

        //Constructor.

        IllegalCoordinateException(int x, int y);

        // Function for the error.

        std::string theCoordinate() const;

    private:

        //Variables of the exception.

        int x,
            y;
};

#endif // ILLEGALCOORDINATEEXCEPTION_H
