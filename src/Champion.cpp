#include "../include/Champion.h"

/**
 * the champion begin from the right / up and then jump to the bottom / left (each turn jump to the opposite) .. until the right diagonal is full.
 * the champion both first and second player, will win any other player of the game.
 */
const vector<size_t> Champion::play(const Board& board) {
    uint counter = 0 ;
    uint maxLength = (uint)board.size()-1 ;
    bool flag = true ;
    uint x1 = 0 , x2 = maxLength, y1 = maxLength, y2 = 0;
    
    while (counter < board.size()) {

        if (flag){
            flag = false ;
           
        std::vector<size_t> c{x1,y1};
            x1++ ;
            y1-- ;
            counter ++;
             if (board[c]=='.')
               return c;
        } else {
            flag = true ;
            std::vector<size_t> c{x2,y2};
            x2-- ;
            y2++ ;
            counter ++;
            
            if (board[c]=='.')
                return c;
        }
        
        }
    return {0,0};  // stam
}
