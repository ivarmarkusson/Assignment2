#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
    public:
        Game(int rows, int cols = 0);
        virtual ~Game();
        virtual void display();
        virtual void initialize_board() = 0;
    protected:
        Board *board_;
        int turn_;
};

#endif // GAME_H
