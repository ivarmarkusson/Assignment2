#ifndef PIECE_H
#define PIECE_H

#include <vector>

struct Position
{
    int x_;
    int y_;
};

class Piece
{
    public:
        Piece()
        {
            symbol_ = '.';
            owner_ = -1;
        };
        Piece(int player,char sym,Position pos, std::vector<std::pair<int,int>> moves)
        {
            posible_moves_ = moves;
            symbol_ = sym;
            owner_ = player;
            position_.x_ = pos.x_;
            position_.y_ = pos.y_;
        }
        virtual ~Piece() {}
        char get_symbol() {return symbol_;}
        int get_owner() {return owner_;}
        Position get_position() {return position_;}
        void set_position(int x, int y)
        {
            position_.x_ = x;
            position_.y_ = y;
        }
        std::vector<std::pair<int,int>> get_posible_moves() {return posible_moves_;}
    protected:
    private:
        char symbol_;
        int owner_;
        Position position_;
        std::vector<std::pair<int,int>> posible_moves_;
};

#endif // PIECE_H
