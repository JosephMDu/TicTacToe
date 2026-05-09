#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
    public:
        HumanPlayer(std::string name, char piece);
    
        void makeMove(Board& b) override;
};

#endif
