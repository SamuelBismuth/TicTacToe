#pragma once

#include <iostream>
#include "Player.h"

class Champion: public Player {
    public:
        const string name() const override { return "Johann & Samuel"; }
        const std::vector<size_t> play(const Board& board) override;
};
