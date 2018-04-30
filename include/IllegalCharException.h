#ifndef ILLEGALCHAREXCEPTION_H
#define ILLEGALCHAREXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IllegalCharException : public exception {
    public:
        IllegalCharException(char pawn);
        char theChar() const;
    protected:

    private:
        char pawn;
};

#endif // ILLEGALCHAREXCEPTION_H
