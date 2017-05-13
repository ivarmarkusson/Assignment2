#ifndef GAME_H
#define GAME_H

#include "Board.h"


class Game
{
    public:
        Game(int rows, int cols = 0);
        virtual ~Game();
        virtual std::vector<std::pair<Piece,Piece>> legal_moves() = 0;
        virtual void start() = 0;
        virtual int evaluate() = 0;
        virtual char terminal_state() = 0;

        void legal();
        void display() const;
        void move(std::string from, std::string to );
        void retract();
        void record_time();
        Position get_int_from_input(std::string input);
        Piece get_at_board(int x, int y);
        int get_turns() {return turn_;};
        void set_level(char l) {level_ = l;}
        char get_level() {return level_;}


    protected:
        Board *board_;
        int turn_;
        std::vector<Board*> timeline_;
        char level_;

    private:
        void increase_turn() {turn_++;};
        void decrease_turn() {turn_--;};

};

#endif // GAME_H
