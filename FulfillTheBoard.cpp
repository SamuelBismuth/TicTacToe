#include "FulfillTheBoard.h"

FulfillTheBoard::FulfillTheBoard(int x, int y, Board* board) {
    this->x = x;
    this->y = y;
    this->board = board;
}

char& FulfillTheBoard::operator= (char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    board->changePawn(pawn, x, y);
    return pawn;
}


