#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Board.h"

class Player
{
    public:
        virtual const std::string name() const { return "BasicPlayer"; }
        virtual const std::vector<size_t> play(const Board& board) { return {0, 0}; }
        char getChar() const;
        void setChar(char pawn);
        char myChar;
};

#endif // PLAYER_H
