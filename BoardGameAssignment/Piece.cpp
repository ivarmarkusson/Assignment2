#include "Piece.h"


Piece::Piece()
{
    symbol_ = '.';
    owner_ = -1;
}

Piece::Piece(int player,char sym,Position pos, std::vector<std::pair<int,int> > moves)
{
    posible_moves_ = moves;
    symbol_ = sym;
    owner_ = player;
    position_.x_ = pos.x_;
    position_.y_ = pos.y_;
}

Piece::~Piece()
{

}

void Piece::set_position(int x, int y)
{
    position_.x_ = x;
    position_.y_ = y;
}

bool Piece::operator== (const Piece& rhs) const
{

}
