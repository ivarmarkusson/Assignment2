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
        Piece();
        Piece(int player,char sym,Position pos, std::vector<std::pair<int,int>> moves);
        virtual ~Piece();
        char get_symbol() const {return symbol_;}
        int get_owner() const {return owner_;}
        Position get_position() const {return position_;}
        void set_position(int x, int y);
        std::vector<std::pair<int,int>> get_posible_moves() const {return posible_moves_;}
        bool operator== (const Piece& rhs ) const;
    protected:
    private:
        char symbol_;
        int owner_;
        Position position_;
        std::vector<std::pair<int,int>> posible_moves_;
};

#endif // PIECE_H
