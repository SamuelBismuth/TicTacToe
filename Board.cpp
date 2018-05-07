/** Includes */

#include "../include/Board.h"
#include "../include/FulfillTheBoard.h"

/**
 * \brief Implementation of the method for the class Board.
 */

/**
 * \brief Constructor for the object Board.
 * \param dimension
 * This constructor build a matrix of dimension n*n and initialize all the case as char.
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

/**
 * \brief Copy constructor of the object Board from another existing Board.
 * This copy constructor is called when Board board2 = board1;
 * \attention only a shallow copy is done here.
 * \param board
 */
Board::Board(const Board& board) {
    Board temp {board.dimension}; //need to free the temp.
    *this = temp;
}

/**
 * \brief D_tor for the object Board.
 * First free the char* for the array of char.
 * Then free all the element of the array.
 */
Board::~Board() {
    free(matrix);
    for(size_t i = 0; i < dimension; i++)
        free(matrix[dimension]);
}

/**
 * \brief Operator to fulfill the Board.
 * This method create a new object of the class FulfillTheBoard.
 * \param point : a vector of Integers.
 * \attention In the assignment we have to add two classes but another solution was to consider that the operator "{}" was a vector.
 * \exception IllegalCoordinateException : if the coordinate are not in the matrix.
 * \return the object FulfillTheBoard.
 * complexity : O(1).
 */
FulfillTheBoard Board::operator[] (vector<int> point) {
    if (point[0] < 0 || point[0] >= dimension || point[1] < 0 || point[1] >= dimension)
        throw IllegalCoordinateException(point[0], point[1]);
    FulfillTheBoard fulfill {point[0], point[1], this};
    return fulfill;
}

/**
 * \brief operator to reset the Board and fulfill all the Board with the char '.'.
 * \param pawn
 * \return the Object Board after the reset.
 * \exception IllegalCharException : if the char is not '.'.
 * complexity : O(n^2) (such that n = dimension).
 */
Board& Board::operator= (char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    for (size_t i = 0; i < dimension; i++) {
        for (size_t j = 0; j < dimension; j++) {
            matrix[i][j] = pawn;
        }
    }
    return *this;
}

/**
 * \brief this operator implements a copy assignment.
 * \attention This operator do a deep copy.
 * \param board
 * \return the Object Board after copy.
 * complexity : O(n^2) (such that n = dimension).
 */
Board& Board::operator= (Board& board) {
    size_t tempDimension = board.getDimension();
    swap(dimension, tempDimension);
    matrix = new char*[dimension];
    for(size_t i = 0; i < dimension; i++)
        matrix[i] = new char[dimension];
    for (size_t j = 0; j < dimension; j++) {
        for (size_t k = 0; k < dimension; k++) {
            matrix[j][k] = board.matrix[j][k];
        }
    }
    return *this;
}

//Setter.

/**
 * \brief this method change pawn in the board. note that this methode used by the class FullfillTheBoard
 * \param pawn
 * \param x
 * \param y
 * complexity : O(1)
 */
void Board::setPawn(char pawn, int x, int y) {
    matrix[x][y] = pawn;
}

//Getters

/**
 * \brief get the matrix.
 * \return the matrix.
 */
char** Board::getMatrix(){
    return matrix ;
}

/**
 * \brief get the dimension of the matrix.
 * \return the dimension.
 */
size_t Board::getDimension(){
    return dimension;
}

//privates methods.

//friends operators.

/**
 * \brief This friend operator prints the board. (As toString in Java).
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
        //If (i != board.dimension - 1) should we put this or not ?
        os << endl;
    }
    return os;
}
