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

void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    xPlayer.setChar('X');
    oPlayer.setChar('0');
    size_t numberOfCase = getDimension() * getDimension();
    size_t count = 0;
    while (count < numberOfCase) {
        vector<size_t> point = xPlayer.play(board());
        boardOfTheGame[point] = 'X';
        if (isGameWinned(board(), point, 'X')) {
            winnerOfTheGame = &xPlayer;
            return;
        }
        point = oPlayer.play(board());
        boardOfTheGame[point] = 'O';
        if (isGameWinned(board(), point, 'O')) {
            winnerOfTheGame = &oPlayer;
            return;
        }
        count += 2;
    }
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
    return *winnerOfTheGame;
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
 bool TicTacToe::isGameWinned(Board board, vector<size_t> point, char player) {
     count up = {1, true};
     count down = {0, true};
	 count right = {1, true};
	 count left = {0, true};
	 count diagonalLeftDown = {1, true};
	 count diagonalLeftUp = {1, true};
	 count diagonalRightDown = {0, true};
	 count diagonalRightUp = {0, true};
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
	if (sumHigh  == board.getDimension() || sumSide == board.getDimension() || sumFirstDiagonal == board.getDimension() || sumSecondDiagonal == board.getDimension())
        return true;
    return false;
}

/**
 * \param point
 * \param player
 * This method \return true is the chip is one chip of the player, and \return false if not.
 */
bool TicTacToe::isPlayer(vector<size_t> point, char player) {
    if (point[0] < 0 || point[0] >= getDimension() || point[1] < 0 || point[1] >= getDimension())
        return false;
    char pawn = boardOfTheGame[point];
	if (player == pawn)
		return true;
	return false;
}


