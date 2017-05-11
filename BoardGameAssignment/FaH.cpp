#include "FaH.h"

FaH::FaH() : Game(8)
{
    Position pos;
    for (int i = 1; i < board_->get_columns(); i+= 2)
    {
        pos.x_ = i;
        pos.y_ = 0;
        Piece h(1,'H', pos);
        board_->place_piece(h);
    }
    pos.x_ = board_->get_columns()/2;
    pos.y_ = board_->get_columns()-1;
    Piece f(0,'F',pos);
    board_->place_piece(f);
}

FaH::~FaH()
{
    //dtor
}
