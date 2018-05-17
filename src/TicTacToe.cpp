/** Include */

#include "../include/TicTacToe.h"

/**
 * \brief Constructor.
 * \param dimension
 */
TicTacToe::TicTacToe(std::size_t dimension)
{
    this->dimension = dimension;
    boardOfTheGame.setBoard(dimension);
}

/**
 * \brief This method manage all the game between two players.
 * The first one plays with X, the second with O.
 * \param xPlayer
 * \param oPlayer
 */
void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    size_t count = 0;
    size_t numberOfCase = dimension * dimension;
    boardOfTheGame = '.';
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    while (count < numberOfCase)
    {
        if (turn('X', xPlayer, oPlayer))  // X won.
            return;
        count++;
        if (turn('O', xPlayer, oPlayer) && count < numberOfCase)  // O won.
            return;
        count++;
    }
    //draw case.
    winnerOfTheGame = &oPlayer;  // By the assignment rules.
}

// Getters.

/**
 * \brief get the board of the game.
 * \return the board of the game.
 */
Board TicTacToe::board() const
{
    return boardOfTheGame;
}

/**
 * \brief get the winner of the game.
 * \return the winner of the game.
 */
Player& TicTacToe::winner() const
{
    return *winnerOfTheGame;
}

//privates methods.

/**
 * \brief This method implements a turn of the game.
 * \param player
 * \param xPlayer
 * \param oPlayer
 * \return true if the game is over, else false.
 * \exception : all the exception caused by an unnatural behavior is caught.
 */
bool TicTacToe::turn(char player, Player& xPlayer, Player& oPlayer) {
    try
        {
            Coordinate point;
            player == 'X' ? point = xPlayer.play(board()) : point = oPlayer.play(board());
            if (boardOfTheGame[point] != '.')
                throw std::string("Illegal Player");
            boardOfTheGame[point] = player;
            if (isGameWinned(board(), point, player))
            {
                player == 'X' ? winnerOfTheGame = &xPlayer : winnerOfTheGame = &oPlayer;
                return true;
            }
            return false;
        }
    catch (...)  // All the exception are caught.
        {
            boardOfTheGame[{0,0}] = 'X';
            player == 'X' ? winnerOfTheGame = &oPlayer : winnerOfTheGame = &xPlayer;
            return true;
        }
}

/**
 * \brief This method should check if the game is over.
 * inspired by the four in a raw implemented in c for another assignment.
 * To do this, the method use a structure calling count (defined in the top).
 * In this structure, there are a counter, and a flag.
 * The counter count how much chip there is in a row.
 * The flag begin true, and if the chip is not of the player, become false.
 * Then, the method calculate the sum of all the counter in the structure.
 * If one of this sum is equal to 4, we got a for in a row, then, the game  is over.
 * \param board.
 * \param point.
 * \param player.
 * \return true if the game is over, else false.
 */
 bool TicTacToe::isGameWinned(Board board, Coordinate point, char player) {
     Count up = {1, true};
     Count down = {0, true};
	 Count right = {1, true};
	 Count left = {0, true};
	 Count diagonalLeftDown = {1, true};
	 Count diagonalLeftUp = {1, true};
	 Count diagonalRightDown = {0, true};
	 Count diagonalRightUp = {0, true};
	 for (int side = 1; side < board.getDimension(); side++) {
        if (isPlayer({point[0], point[1] + side}, player) && up.flag)
            up.sum++;
        else
            up.flag = false;
        if (isPlayer({point[0], point[1] - side}, player) && down.flag)
            down.sum++;
        else
            down.flag = false;
		if (isPlayer({point[0] + side, point[1]}, player) && right.flag)
            right.sum++;
		else
            right.flag = false;
		if (isPlayer({point[0] - side, point[1]}, player) && left.flag)
            left.sum++;
		else
            left.flag = false;
		if (isPlayer({point[0] - side, point[1] - side}, player) && diagonalLeftDown.flag)
            diagonalLeftDown.sum++;
		else
            diagonalLeftDown.flag = false;
		if (isPlayer({point[0] - side, point[1] + side}, player) && diagonalLeftUp.flag)
            diagonalLeftUp.sum++;
		else
            diagonalLeftUp.flag = false;
		if (isPlayer({point[0] + side, point[1] - side}, player) && diagonalRightDown.flag)
            diagonalRightDown.sum++;
		else
            diagonalRightDown.flag = false;
		if (isPlayer({point[0] + side, point[1] + side}, player) && diagonalRightUp.flag)
            diagonalRightUp.sum++;
		else
            diagonalRightUp.flag = false;
	}
	int sumHigh = up.sum + down.sum;
	int sumSide = right.sum + left.sum;
	int sumFirstDiagonal = diagonalLeftDown.sum + diagonalRightUp.sum;
	int sumSecondDiagonal = diagonalLeftUp.sum + diagonalRightDown.sum;
     if (sumHigh  == board.getDimension() || sumSide == board.getDimension() || sumFirstDiagonal == board.getDimension() || sumSecondDiagonal == board.getDimension()) {
         return true;
     }
    return false;
}

/**
 * \param point
 * \param player
 * This method \return true is the chip is one chip of the player, and \return false if not.
 */
bool TicTacToe::isPlayer(Coordinate point, char player) {
    if (point[0] < 0 || point[0] >= dimension || point[1] < 0 || point[1] >= dimension)
        return false;
    char pawn = boardOfTheGame[point];
	if (player == pawn)
		return true;
	return false;
}
