#include "Player.h"

char Player::getChar() const
{
    return myChar;
}

void Player::setChar(char pawn)
{
    myChar = pawn;
}

//TODO : ARRANGE THE RANDOM WAY TO CHOOSE. (OR SIMPLY IMPLEMENT CHAMPION HERE)
const std::vector<size_t> Player::play(const Board& board) {
    for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
			std::vector<size_t> c{std::rand() % board.getDimension(), std::rand() % board.getDimension()};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}
