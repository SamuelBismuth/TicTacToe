#include "Board.h"
#include "FulfillTheBoard.h"

/**
 * \brief Constructor of the object Board.
 * \param dimension
 * complexity : O(n^2) (such that n = dimension).
 */
Board::Board(const size_t dimension) {
    this->dimension = dimension;
    matrix = new char*[dimension];
    for(size_t i = 0; i < dimension; i++)
        matrix[i] = new char[dimension];
    for (size_t j = 0; j < dimension; j++) {
        for (size_t k = 0; k < dimension; k++) {
            matrix[j][k] = '.';
        }
    }
}

Board::Board(const Board& board) {
    Board temp {board.dimension};
    *this = temp; //because of this maybe.
}

FulfillTheBoard Board::operator[] (vector<int> point) {
    if (point[0] < 0 || point[0] >= dimension || point[1] < 0 || point[1] >= dimension)
        throw IllegalCoordinateException(point[0], point[1]);
    FulfillTheBoard fulfill {point[0], point[1], this};
    return fulfill;
}

Board& Board::operator= (char pawn) {
    cout << "hello" << endl;
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    for (size_t i = 0; i < dimension; i++) {
        for (size_t j = 0; j < dimension; j++) {
            matrix[i][j] = pawn;
        }
    }
    return *this;
}

//Board& Board::operator= (Board& board) {
   // cout << "hello" << endl;
//}


void Board::changePawn(char pawn, int x, int y) {
    matrix[x][y] = pawn;
}

//privates methods.

//friends operators.

/**
 * \brief This friend operator print the board. (As toString in Java).
 * \param os
 * \param board
 * \return os.
 * Complexity : O(1).
 */
ostream& operator<< (ostream& os, const Board& board) {
    for (size_t i = 0; i < board.dimension; i++) {
        for (size_t j = 0; j < board.dimension; j++) {
            os << board.matrix[i][j];
        }
        //if (i != board.dimension - 1) should we put this or not ?
            os << endl;
    }
    return os;
}
