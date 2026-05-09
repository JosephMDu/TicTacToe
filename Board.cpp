#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board_[i][j] = ' ';
        }
    }
}

void Board::printBoard() const{
    cout<< "\n  0 1 2\n";
    for(int i = 0; i < 3; i++){
        cout<< i << " ";
        for (int j = 0; j < 3; j++){
            cout << board_[i][j] << (j < 2 ? "|" : "");
        }
        if (i < 2){
            cout<<"\n  -----\n";
        }
    }
    cout<< "\n";
}
 
bool Board::place(int r, int c, char p){
    if (r >= 0 && r < 3 && c >= 0 && r <= 3 && isEmpty(r, c)){
        board_[r][c] = p;
        return true;
    }
    return false;
}

bool Board::isFull() const{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board_[i][j] == ' ') return false;
        }
    }
    return true;
}

char Board::checkWin() const{
    for(int i=0; i<3; i++) {
        if(board_[i][0] != ' ' && board_[i][0] == board_[i][1] && board_[i][1] == board_[i][2]) return board_[i][0];
        if(board_[0][i] != ' ' && board_[0][i] == board_[1][i] && board_[1][i] == board_[2][i]) return board_[0][i];
    }
    // Check Diagonals
    if(board_[0][0] != ' ' && board_[0][0] == board_[1][1] && board_[1][1] == board_[2][2]) return board_[0][0];
    if(board_[0][2] != ' ' && board_[0][2] == board_[1][1] && board_[1][1] == board_[2][0]) return board_[0][2];
    return ' ';
}

bool Board::isEmpty(int r, int c) const{
    return board_[r][c] == ' ';
}

char Board::getCell(int r, int c) const{
    if (r >= 0 && r < 3 && c >= 0 && c < 3) {
        return board_[r][c];
    }
    return ' ';
}

void Board::remove(int r, int c) {
    if (r >= 0 && r < 3 && c >= 0 && c < 3) {
        this->board_[r][c] = ' ';
    } 
}
