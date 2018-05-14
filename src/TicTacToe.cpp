#include "TicTacToe.h"

TicTacToe::TicTacToe(size_t dimension)
{
    this->dimension = dimension;
    boardOfTheGame.setBoard(dimension);
}


TicTacToe::~TicTacToe()
{
    //dtor
}

TicTacToe& TicTacToe::play(Player xPlayer, Player oPlayer)
{
    //while there is no winner
    boardOfTheGame[xPlayer.play(board())] = 'X';
    //check if game finish
    boardOfTheGame[oPlayer.play(board())] = 'O';
}

Board TicTacToe::board() const
{
    return boardOfTheGame;
}

size_t TicTacToe::getDimension() const
{
    return dimension;
}

Player& TicTacToe::winner() const {
    return winnerOfTheGame;
}

/**
 * \brief
 * We use recursive programming to implement this method.
 * \param
 * \return
 */
bool TicTacToe::isGameWinX(size_t x, size_t y) {
    if (x > getDimension() && y > getDimension())
        return true;
    if (boardOfTheGame[x][y] == 'X')
        return isGameWinX(x + 1, y + 1) || isGameWinX(x, y + 1) || isGameWinX(x + 1, y);
    return false;
}

bool TicTacToe::isGameWinY(Board board) {

}
