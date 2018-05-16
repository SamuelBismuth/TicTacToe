#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe(size_t dimension)
{
    this->dimension = dimension;
    boardOfTheGame.setBoard(dimension);
}


TicTacToe::~TicTacToe()
{
    //dtor
}

/**
 * \param xPlayer
 * \param oPlayer
 * This method manage all the game between two players. the first one plays with X, the second with O.
 */
void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    size_t count = 0;
    size_t numberOfCase = Start(xPlayer,oPlayer);
    while (count < numberOfCase) {
        TurnOfplayerX(xPlayer);
        if(Won) return;
        
        TurnOfplayerO(oPlayer);
        if(Won) return;
        
        count += 2;
    }
    
}

/**
 * \param xPlayer
 * \param oPlayer
 * This method Initialise the game to start a new game.
 * \return the number of case in the new board.
 */
size_t TicTacToe::Start(Player& xPlayer, Player& oPlayer){
    resetTheBoard();
    Won = false ;
    illegalPlayer = false;
    xPlayer.setChar('X');
    oPlayer.setChar('0');
    size_t numberOfCase = getDimension() * getDimension();
    return numberOfCase;
}

/**
 * \param Xplayer
 * This method manage the turn of the X player.
 */
void TicTacToe::TurnOfplayerX(Player& Xplayer){
    try{
    vector<size_t> point = Xplayer.play(board());
    if (boardOfTheGame[point]=='.' && !illegalPlayer)
        boardOfTheGame[point] = 'X';
    else if (!illegalPlayer){
       illegalPlayer = true ;
     return ;
        }
    if (isGameWinned(board(), point, 'X') || illegalPlayer) {
        winnerOfTheGame = &Xplayer;
        Won = true ;
  }
} catch (...) {
    illegalPlayer = true ; }
}

/**
 * \param Oplayer
 * This method manage the turn of the X player.
 */
    void TicTacToe::TurnOfplayerO(Player& Oplayer){
    try{
    vector<size_t> point = Oplayer.play(board());
    if (boardOfTheGame[point]=='.' && !illegalPlayer)
        boardOfTheGame[point] = 'O';
    else if (!illegalPlayer){
        illegalPlayer = true ;
        return ;
    }
    if (isGameWinned(board(), point, 'O') || illegalPlayer) {
        winnerOfTheGame = &Oplayer;
        Won = true ;
    }
    } catch (...) { illegalPlayer = true ;}
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
bool TicTacToe::isPlayer(vector<size_t> point, char player) {
    if (point[0] < 0 || point[0] >= getDimension() || point[1] < 0 || point[1] >= getDimension())
        return false;
    char pawn = boardOfTheGame[point];
	if (player == pawn)
		return true;
	return false;
}

void TicTacToe::resetTheBoard(){
    boardOfTheGame = '.';
}


