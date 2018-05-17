#ifndef TICTACTOE_H
#define TICTACTOE_H

/** Includes */

#include <iostream>

#include "Player.h"
#include "Board.h"
#include "Champion.h"

typedef std::vector<std::size_t> Coordinate;

/**
 * \brief This class is a TicTacToe game.
 * \author Johann and Samuel.
 */
class TicTacToe
{
    public:

        //constructor.

        TicTacToe(size_t dimension);

        //functions used in the main file for the good of the game.

        void play(Player& xPlayer, Player& oPlayer);
        Board board() const;
        Player& winner() const;

    private:

        //help functions.

        bool isGameWinned(Board board, Coordinate point, char player);
        bool isPlayer(Coordinate point, char player);
        void initializeTheGame(Player& xPlayer, Player& oPlayer);
        bool turn(char player, Player& xPlayer, Player& oPlayer);

        //variables.

        size_t dimension;
        Board boardOfTheGame;
        Player* winnerOfTheGame;
};

/**
 * \brief structure Count.
 * This structure is used to count the number of piece and know if the game is finish or not.
 */
typedef struct Count {
	int sum;
	bool flag;
} count;

#endif // TICTACTOE_H
