#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player{
    public:
        AIPlayer(std::string name, char piece);
    
        void makeMove(Board& b) override;

};

#endif
