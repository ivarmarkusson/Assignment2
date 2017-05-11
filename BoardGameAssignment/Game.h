#ifndef GAME_H
#define GAME_H

#include "Board.h"


class Game
{
    public:
        Game(int rows, int cols = 0);
        virtual ~Game();
        virtual std::vector<std::pair<Piece,Piece>> legal_moves() = 0;
        void display() const;
        void move(std::string from, std::string to );
        void increase_turn() {turn_++;};
        void decrease_turn() {turn_--;};
        void retract();
        void record_time();
        Position convert_coord(int x, int y);
        Position get_int_from_input(std::string input);
        Piece get_at_board(int x, int y);
    protected:
        Board *board_;
        int turn_;
        std::vector<Board*> timeline_;
    private:

};

#endif // GAME_H
