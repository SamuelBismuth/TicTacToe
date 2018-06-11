#ifndef BOARD_H
#define BOARD_H

/** Includes */

#include <iostream>
#include <vector>  // For the vector use (which replaces coordinate).
#include <cmath>  // For the sqrt function.
#include <fstream>  // For the image.
#include <string>  // For the string variable.
#include <sys/stat.h>  // For the stat buffer structure.

#include "Piece.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

/** based on our teacher's github :
 * https://github.com/erelsgl/ariel-cpp-5778/blob/master/week07-diamond-rtti/5-image/image.cpp
 */
struct RGB
{
    uint8_t red, green, blue;
public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

/**
 * \brief This class is a Board.
 * This board is the base of the game connection 4.
 * \author Johann and Samuel.
 */
class Board
{

public:

    //Constructors

    Board();
    Board(const Board& board);        //Copy constructor.
    Board(std::size_t dimension);    //Constructor

    //D_tor

    ~Board();

    //Operators

    Piece& operator[] (std::vector<std::size_t> point) const;
    const Board& operator= (char pawn) const;
    Board& operator= (const Board& board);

    // Size

    size_t size() const;

    // Output the board.

    std::string draw(int pixel);

    //Getter.

    size_t getDimension() const;

    //Setter

    void setBoard(const std::size_t dimension);
    void setDimension(const std::size_t dimension);
    void setMatrix(const std::size_t dimension);

private:

    // Variables of the object Board.

    std::size_t dimension;
    Piece** matrix;

    // Help function.

    void fill(char pawn) const;

    // Help function for the picture

    void focus(RGB image[], int& pixel);
    void create_O(RGB image[], int x, int y, int pas, int pas_x, int pas_y);
    void create_X(RGB image[], int x, int y, int pas, int pas_x, int pas_y);
    void create_Rectangle(RGB image[], int x, int y, int pas, int pas_x, int pas_y);
    std::string new_name();
    bool exists_file (const std::string& name);

    // Operator << to print the Board.

    friend std::ostream& operator<< (std::ostream& os, const Board& board);

    // Operator >> to output the Board.

    friend std::istream& operator>> (std::istream &input, Board& board);
};

#endif // BOARD_H
