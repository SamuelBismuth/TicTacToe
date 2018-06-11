/** Include */

#include "../include/Champion.h"

/**
 * \brief Implementation of the method for the class Champion.
 */

/**
 * \brief This method implements the dummy of the champion.
 * \param board
 * \return The point where the champion want to put his piece.
 * The champion begin from the right / up and then jump to the bottom / left (each turn jump to the opposite) .. until the right diagonal is full.
 * The champion both side : as first and as second player, will win any other player of the game.
 */
const std::vector<std::size_t> Champion::play(const Board& board) {
    std::size_t counter = 0;
    std::size_t maxLength = (std::size_t) board.size() - 1;
    bool flag = true;
    std::size_t x1 = 0 , x2 = maxLength, y1 = maxLength, y2 = 0;
    while (counter < board.size())
    {
        if (flag)
        {
            flag = false;
            std::vector<std::size_t> c{x1,y1};
            x1++ ;
            y1-- ;
            counter ++;
            if (board[c]=='.')
               return c;
        }
        else
        {
            flag = true ;
            std::vector<std::size_t> c{x2, y2};
            x2-- ;
            y2++ ;
            counter ++;
            if (board[c]=='.')
                return c;
        }
    }
    return {0,0};
}
