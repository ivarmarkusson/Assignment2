#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Piece.h"

class Player
{
    public:
        Player(int player, char sym, int num_pieces) : player_(player), symbol_(sym) {};
        virtual ~Player() {};
        char get_symbol() {return symbol_;};
        int get_player() {return player_;};
    protected:
    private:
        int player_;
        char symbol_;
};

#endif // PLAYER_H
