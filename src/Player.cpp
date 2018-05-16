/** Include */

#include "../include/Player.h"

/**
 * \brief get the char of the player.
 * \return the char of the player.
 */
char Player::getChar() const
{
    return myChar;
}

/**
 * \brief set the char of the player.
 * \param the char of the player.
 */
void Player::setChar(char pawn)
{
    myChar = pawn;
}
