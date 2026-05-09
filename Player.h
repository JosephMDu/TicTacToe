




#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Board;

class Player {
    public:
        //constructor
        Player(std::string name, char piece);

        //destructor
        virtual ~Player();

        // make move function (will implement differently for human player and AI Player)
        virtual void makeMove(Board& b) = 0;

        char getPiece() const;
        std::string getName() const;
        
    protected:
        std::string name_;
        char piece_;
};

#endif
