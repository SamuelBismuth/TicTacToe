#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include "Player.h"
#include "Board.h"

class TicTacToe
{
    public:
        TicTacToe(size_t dimension);
        virtual ~TicTacToe();
        TicTacToe& play(Player xPlayer, Player oPlayer);
        Board board() const;
        Player& winner() const;
        size_t getDimension() const;

    protected:

    private:
        size_t dimension;
        Board boardOfTheGame;
        Player winnerOfTheGame;
};

#endif // TICTACTOE_H
