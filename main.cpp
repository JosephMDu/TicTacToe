#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    Board gameBoard;
    vector<Player*> players;

    int choice;
    cout << "Welcome to a game of Tic-Tac-Toe!\n";
    cout << "1. Human vs Human \n2. Human vs AI\n";
    cout << "choose a game mode:";
    cin >> choice;

    players.push_back(new HumanPlayer("Player 1", 'X'));
    if (choice == 1){
        players.push_back(new HumanPlayer("Player 2", 'O'));
    } else {
        players.push_back(new AIPlayer("Computer", 'O'));
    }

    int turn = 0;
    while (gameBoard.checkWin() == ' ' && !(gameBoard.isFull())){
        gameBoard.printBoard();

        players[turn%2]->makeMove(gameBoard);
        turn++;
    }

    gameBoard.printBoard();
    char winner = gameBoard.checkWin();
    if (winner != ' '){
        cout << "The winner is " << winner << "!\n";
    } else {
        cout << "It's a Tie!\n";
    }

    for(auto p : players) delete p;

    return 0;

}
