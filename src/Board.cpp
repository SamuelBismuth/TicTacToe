/** Include */

#include "../include/Board.h"

/**
 * \brief Implementation of the method for the class Board.
 */

 /**
 * \brief Empty constructor for the object Board.
 * complexity : O(1).
 */
Board::Board() {
    this->dimension = 0;
    matrix = new Piece*[dimension];
    for(std::size_t i = 0; i < dimension; i++)
        matrix[i] = new Piece[dimension];
}

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
const Board& Board::operator= (char pawn) const {
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

/**
 * \brief Output of the picture.
 * based on our teacher's github :
 * https://github.com/erelsgl/ariel-cpp-5778/blob/master/week07-diamond-rtti/5-image/image.cpp
 * Here you need to create a matrix [pixel][pixel] which contains pixel from 0 to 255.
 * Each number represent a color (you may change color to differentiate x from 0).
 * You need to divide the matrix into sub-matrix, in each sub-matrix there is a pawn.
 * ATTENTION do not forget the board (that mean let a line to separate the case as follow :
 *
 * X | O | X
 * ---------
 * X | O | O
 * ---------
 * O | O | O
 *
 * Since you separate the matrix into sub-matrix (dynamically of course cause the size of the board can change).
 * Send all the sub-matrix to get fill.
 * When i mean separate the matrix i mean virtually cause you don't need to create new matrix, only put number
 * (x and y)and a value which is the "pas" of the case.
 * \param pixel
 * \return the filename.
 * complexity : O(pixel * pixel).
 */
std::string Board::draw(int pixel)
{
    std::string nameFile = new_name();
    std::ofstream imageFile(nameFile, std::ios::out | std::ios::binary);
    RGB image[pixel * pixel];
    focus(image, pixel);
    imageFile << "P6" << std::endl << pixel << " " << pixel << std::endl << 255 << std::endl;
    int pas = pixel / dimension;
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for(int x = 0; x < pas; x++)
            {
                for(int y = 0; y < pas; y++)
                {
                    if (matrix[i][j].get_piece() == 'X')
                        create_X(image, x, y, pas, pas * i, pas * j);
                    else if (matrix[i][j].get_piece() == 'O')
                        create_O(image, x, y, pas, pas * i, pas * j);
                    create_Rectangle(image, x, y, pas, pas * i, pas * j);
                }
            }
        }
    }
    imageFile.write(reinterpret_cast<char*>(&image), 3 * pixel * pixel);
    imageFile.close();
    return (std::string) nameFile;
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
void Board::fill(char pawn) const {
    if (pawn != '.' && pawn != 'X' && pawn != 'O')
        throw IllegalCharException(pawn);
    for (std::size_t i = 0; i < dimension; i++) {
        for (std::size_t j = 0; j < dimension; j++) {
            matrix[i][j] = pawn;
        }
    }
}

void Board::focus(RGB image[], int& pixel) {
    int counter = 0;
    if (!(pixel % dimension == 0))
    {
         while(!(pixel % dimension == 0))
        {
            pixel--;
            counter++;
        }
    }
    while(pixel * pixel - counter == pixel * pixel)
    {
        image[pixel * pixel - counter].red = 0;
        counter--;
    }
}

/**
 * \brief create a O.
 * \param image
 * \param x
 * \param y
 * \param pas
 * \param pas_x
 * \param pas_y
 * This method draw a circle.
 * The color may change by changing the numbers.
 */
void Board::create_O(RGB image[], int x, int y, int pas, int pas_x, int pas_y)
{
    double c = pas / 2;
    double function_circle = std::sqrt((x - c) * (x - c) + (y - c) * (y - c));
    if (function_circle <= pas / 2 && function_circle >= 19 * pas / 40)
        image[pas * dimension * (pas_x + x) + (pas_y + y)].red = (250);
}

/**
 * \brief create a X.
 * \param image
 * \param x
 * \param y
 * \param pas
 * \param pas_x
 * \param pas_y
 * This method draw a X.
 * The color may change by changing the numbers.
 */
void Board::create_X(RGB image[], int x, int y, int pas, int pas_x, int pas_y)
{
    if (x == y && x <= pas && y <= pas)
    {
        image[pas * dimension * (pas_x + x) + (pas_y + y)].blue = (250); //here is the segmentation fault
        image[pas * dimension * ((pas_x + pas) - x) + (pas_y + y)].blue = (250);
    }
}

/**
 * \brief create a rectangle.
 * \param image
 * \param x
 * \param y
 * \param pas
 * \param pas_x
 * \param pas_y
 * This method draw a rectangle.
 * The color may change by changing the numbers.
 */
void Board::create_Rectangle(RGB image[], int x, int y, int pas, int pas_x, int pas_y)
{
    if ((x + pas_x == pas_x) || (y + pas_y == pas_y) ||(x + pas_x == pas + pas_x - 1) || (y + + pas_y == pas + pas_y - 1))
    {
        image[pas * dimension * (pas_x + x) + (pas_y + y)].green = (255);
        image[pas * dimension * (pas_x + x) + (pas_y + y)].blue = (255);
        image[pas * dimension * (pas_x + x) + (pas_y + y)].red = (255);
    }
}

/**
 * \brief Get a new name for the picture file.
 * This method increment i until a new name is found.
 * \return the new name.
 */
std::string Board::new_name()
{
    int i = 2;
    std::string filename = "board.ppm";
    while (exists_file(filename))
    {
        filename = "board"+ std::to_string(i)+".ppm" ;
        i++ ;
    }
    return filename;
}

/**
 * \brief check if a file exists.
 * \param name
 * \return true if the file exist, else false.
 */
bool Board::exists_file (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
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

/**
 * \brief operator cin.
 * This method turn the txt file into a board object corresponding to the pawns.
 * \param input
 * \param board
 * \return input
 */
std::istream& operator>> (std::istream &input, Board& board)
{
    std::string str;
    size_t dim = 0, raw = 0;
    input >> str;
    dim = str.length();
    board.setBoard(dim);
    while (input)
    {
        for (size_t j = 0; j < dim; j++)
            board[{raw, j}] = str[j];
        input >> str;
        raw++;
    }
    return input;
}
