#ifndef ILLEGALCOORDINATEEXCEPTION_H
#define ILLEGALCOORDINATEEXCEPTION_H

/** Includes */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/**
 * \brief This exception class controls if the char are the good one.
 * \author Johann and Samuel.
 */
class IllegalCoordinateException : public exception {

    public:
        //Constructor.

        IllegalCoordinateException(int x, int y);

        // Function for the error.

        string theCoordinate() const;

    protected:

    private:

        //Variables of the exception.

        int x,
            y;
};

#endif // ILLEGALCOORDINATEEXCEPTION_H
