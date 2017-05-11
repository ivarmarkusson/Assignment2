#include "MBT.h"

MBT::MBT(int rows, int cols) : Game(rows, cols)
{
    Position pos1, pos2;
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos1.x_ = i;
        pos2.x_ = i;
        pos1.y_ = board_->get_rows()-1;
        pos2.y_ = 0;
        Piece p1(0,'M',pos1);
        Piece p2(1,'m',pos2);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos1.x_ = i;
        pos2.x_ = i;
        pos1.y_ = board_->get_rows()-2;
        pos2.y_ = 1;
        Piece p1(0,'P',pos1);
        Piece p2(1,'p',pos2);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
}

MBT::~MBT()
{

}

