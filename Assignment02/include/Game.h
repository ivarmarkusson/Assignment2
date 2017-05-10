#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
    public:
        Game(int rows, int cols = 0);
        virtual ~Game();
        void display();
        virtual void initialize_board() = 0;
        virtual void move(Piece from, Piece to);
    protected:
        Board *board_;
        int turn_;
    private:
};

#endif // GAME_H
