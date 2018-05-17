#ifndef PLAYER_H
#define PLAYER_H

/** Includes */

#include <iostream>
#include <string>

#include "Board.h"

/**
 * \brief This class is a Player.
 * A player is a virtual class which will use b some dummy player.
 * \author Johann and Samuel.
 */
class Player
{
    public:

        //behave function.

        virtual const std::string name() const { return "TiePlayer"; }
        virtual const std::vector<size_t> play(const Board& board) { return {0, 0}; }

        //getter.

        char getChar() const;

        //setter.

        void setChar(char pawn);

        //variable.

        char myChar;
};

#endif // PLAYER_H
