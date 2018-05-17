/** Include */

#include "Board.h"

/**
 * \brief Implementation of the method for the class Board.
 */

 /**
 * \brief Empty constructor for the object Board.
 * complexity : O(1).
 */
Board::Board() {}

/**
 * \brief Constructor for the object Board.
 * \param dimension
 * This constructor build a matrix of dimension n and initialize all the case as Piece.
 * complexity : O(n) (such that n = dimension).
 */
Board::Board(const std::size_t dimension) {
    this->dimension = dimension;
    matrix = new Piece*[dimension];
    for(std::size_t i = 0; i < dimension; i++)
        matrix[i] = new Piece[dimension];
}

/**
 * \brief Copy constructor of the object Board from another existing Board.
 * This copy constructor is called when Board board2 = board1;
 * \attention only a shallow copy is done here.
 * \param board
 */
Board::Board(const Board& board) {
    dimension = board.dimension;
    matrix = new Piece*[dimension];
    for(std::size_t i = 0; i < dimension; i++)
        matrix[i] = new Piece[dimension];
    for (std::size_t i = 0; i < dimension; i++) {
        for (std::size_t j = 0; j < dimension; j++) {
            matrix[i][j].set_piece(board.matrix[i][j].get_piece());
        }
    }
}

/**
 * \brief D_tor for the object Board.
 * First free the char* for the array of char.
 * Then free all the element of the array.
 */
Board::~Board() {
    for (std::size_t i = 0; i < dimension; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * \brief Operator to fulfill the Board.
 * This method create a new object of the class FulfillTheBoard.
 * \param point : a vector of Integers.
 * \attention In the assignment we have to add two classes but another solution was to consider that the operator "{}" was a vector.
 * \exception IllegalCoordinateException : if the coordinate are not in the matrix.
 * \return the object Piece.
 * complexity : O(1).
 */
Piece& Board::operator[] (std::vector<std::size_t> point) const {
    if (point[0] < 0 || point[0] >= dimension || point[1] < 0 || point[1] >= dimension)
        throw IllegalCoordinateException(point[0], point[1]);
    return matrix[point[0]][point[1]];
}

/**
 * \brief operator to reset the Board and fulfill all the Board with the char '.'.
 * \param pawn
 * \return the Object Board after the reset.
 * \exception IllegalCharException : if the char is not '.'.
 * complexity : O(n) (such that n = dimension).
 */
Board& Board::operator= (char pawn) {
    fill(pawn);
    return *this;
}

/**
 * \brief this operator implements a copy assignment.
 * \attention This operator do a deep copy.
 * \param board
 * \return the Object Board after copy.
 * complexity : O(n) (such that n = dimension).
 */
Board& Board::operator= (const Board& board) {
    this->~Board();
    dimension = board.getDimension();
    matrix = new Piece*[dimension];
    for(std::size_t i = 0; i < dimension; i++)
        matrix[i] = new Piece[dimension];
    for(std::size_t i = 0; i < dimension; i++) {
        for(std::size_t j = 0; j < dimension; j++) {
            matrix[i][j].set_piece(board.matrix[i][j].get_piece());
        }
    }
    return *this;
}

//size

/**
 * \brief get the dimension
 * \return the dimension of the board.
 * Complexity : O(1).
 */
std::size_t Board::size() const {
    return getDimension();
}


//Getter

/**
 * \brief get the dimension of the matrix.
 * \return the dimension.
 * Complexity : O(1).
 */
std::size_t Board::getDimension() const {
    return dimension;
}

//Setter

/**
 * \brief set a new Board.
 * \param dimension
 * Complexity : O(n).
 */
void Board::setBoard(const std::size_t dimension) {
    setDimension(dimension);
    setMatrix(dimension);
}

/**
 * \brief set a new dimension.
 * \param dimension
 * Complexity : O(1).
 */
void Board::setDimension(const std::size_t dimension) {
    this->dimension = dimension;
}

/**
 * \brief set a new matrix.
 * \param dimension
 * Complexity : O(n).
 */
void Board::setMatrix(const std::size_t dimension) {
    matrix = new Piece*[dimension];
    for(std::size_t i = 0; i < dimension; i++)
        matrix[i] = new Piece[dimension];
}

//privates methods.

/**
 * \brief fill the board with only one char.
 * \param pawn
 * Complexity : O(n^2).
 */
void Board::fill(char pawn) {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    for (std::size_t i = 0; i < dimension; i++) {
        for (std::size_t j = 0; j < dimension; j++) {
            matrix[i][j] = pawn;
        }
    }
}

//friends operators.

/**
 * \brief This friend operator prints the board. (As toString in Java).
 * \param os
 * \param board
 * \return os.
 * Complexity : O(n^2).
 */
std::ostream& operator<< (std::ostream& os, const Board& board) {
    for (std::size_t i = 0; i < board.getDimension(); i++) {
        for (std::size_t j = 0; j < board.getDimension(); j++) {
            os << board.matrix[i][j].get_piece();
        }
        os << std::endl;
    }
    return os;
}
