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
    /*bool check1 = symbol_ == rhs.get_symbol() && owner_ == rhs.get_owner() && position_.x_  == rhs.get_position().x_
    && position_.y_ == rhs.get_position().y_;

    bool check2;
    if (posible_moves_.size() == rhs.get_posible_moves().size())
    {
        for (size_t i = 0; i < posible_moves_.size(); i++)
        {
            if (posible_moves_[i].first)
        }
    }*/
    return false;
}
