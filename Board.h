#ifndef BOARD_H
#define BOARD_H

class Board {
    public:
        Board();
        void printBoard() const;
        bool place(int r, int c, char p);
        bool isFull() const;
        char checkWin() const;
        bool isEmpty(int r, int c) const;
        char getCell(int r, int c) const;
        void remove(int r, int c);


    private:
        char board_[3][3];
        

};

#endif
