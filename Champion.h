#pragma once

/** Includes */

#include <iostream>

#include "Player.h"

/**
 * \brief This class is a Champion.
 * This class extends the Player class.
 * \author Johann and Samuel.
 */
class Champion: public Player {

    public:

        const std::string name() const override { return "Johann & Samuel"; }
        const std::vector<std::size_t> play(const Board& board) override;
};


