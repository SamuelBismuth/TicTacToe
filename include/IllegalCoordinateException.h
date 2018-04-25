#ifndef ILLEGALCOORDINATEEXCEPTION_H
#define ILLEGALCOORDINATEEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IllegalCoordinateException : public exception {
    public:
        IllegalCoordinateException(int x, int y);
        string theCoordinate() const;
    protected:

    private:
        int x,
            y;
};

#endif // ILLEGALCOORDINATEEXCEPTION_H
