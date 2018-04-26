#include "IllegalCharException.h"

IllegalCharException::IllegalCharException(char pawn) {
    this->pawn = pawn;
}

char IllegalCharException::theChar() const {
    return pawn;
}



