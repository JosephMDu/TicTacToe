#include "HumanPlayer.h"
#include "Board.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(std::string name, char piece)
    : Player(name, piece){
}

void HumanPlayer::makeMove(Board& b){
    int r, c;
    bool success = false;

    while (!success){
        cout << name_ << " ("<<piece_<<") "<<", enter row and column (0-2) seperated with a space: ";
        if (cin >> r >> c){
            if (b.place(r, c, piece_)){
                success = true;
            } else {
                cout << "Cell is occupied or out of bounds. Try again.\n";
            }
        } else {
            cout << "Invalid input. Please enter numbers only.\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
        }
    }
}
