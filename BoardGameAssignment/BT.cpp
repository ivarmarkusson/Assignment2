#include "BT.h"
#include <iostream>

BT::BT(int rows, int cols) : Game(rows, cols){}

BT::~BT()
{
    //dtor
}

void BT::initialize_board()
{
    Position pos1, pos2;
    for (int i = 0; i < board_->get_columns(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            pos1.x_ = i;
            pos2.x_ = i;
            pos1.y_ = board_->get_rows()-j-1;
            pos2.y_ = j;
            Piece p1(0,'P',pos1);
            Piece p2(1,'p',pos2);
            board_->place_piece(p1);
            board_->place_piece(p2);
        }
    }
}
