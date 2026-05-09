#include "AIPlayer.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

AIPlayer::AIPlayer(std::string name, char piece)
    : Player(name, piece){
}

void AIPlayer::makeMove(Board& b){
    cout << "Computer analyzing moves...\n";

    char opponent = (piece_ == 'X') ? 'O' : 'X'; 

    // Try and Win
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (b.isEmpty(i, j)){
                b.place(i, j, piece_); 
                if (b.checkWin() == piece_) {
                    return;
                }
                b.remove(i, j);
            }
        }
    }

    // Block
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(b.isEmpty(i, j)){
                b.place(i, j, opponent);
                if (b.checkWin() == opponent){
                    b.remove(i, j);
                    b.place(i, j, piece_);
                    return;

                }
                b.remove(i,j);
            }
        }
    }

    // random position if no immediate block or win
    bool moved = false;

    int r = rand() % 3;
    int c = rand() % 3;

    while(!moved){
        if (b.isEmpty(r, c)){
            b.place(r, c, piece_);
            moved = true;
        }
    }
    return;
}
