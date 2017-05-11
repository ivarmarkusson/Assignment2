#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>

class Game
{
    public:
        Game(int rows, int cols = 0);
        virtual ~Game();
        void display() const;
        void move(std::string from, std::string to );


    protected:
        Board *board_;
        int turn_;
    private:
        Position get_int_from_input(std::string input);
};

#endif // GAME_H
