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
        void play(Player& xPlayer, Player& oPlayer);
        void resetTheBoard();
        Board board() const;
        Player& winner() const;
        size_t getDimension() const;


    protected:

    private:
        bool isGameWinned(Board board, vector<size_t> point, char player);
        bool isPlayer(vector<size_t> point, char player);
        size_t dimension;
        Board boardOfTheGame;
        Player* winnerOfTheGame;
};

#endif // TICTACTOE_H

typedef struct Count {
	int sum;
	bool flag;
} count;
