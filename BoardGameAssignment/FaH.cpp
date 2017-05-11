#include "FaH.h"
#include <vector>

using namespace std;

FaH::FaH() : Game(8)
{
    vector<pair<int,int>> movesHound;
    movesHound.push_back(make_pair(1,1));
    movesHound.push_back(make_pair(-1,1));

    vector<pair<int,int>> movesFox;
    movesFox.push_back(make_pair(1,1));
    movesFox.push_back(make_pair(-1,1));
    movesFox.push_back(make_pair(1,-1));
    movesFox.push_back(make_pair(-1,-1));

    Position pos;
    for (int i = 1; i < board_->get_columns(); i+= 2)
    {
        pos.x_ = i;
        pos.y_ = 0;
        Piece h(1,'H', pos, movesHound);
        board_->place_piece(h);
    }
    pos.x_ = board_->get_columns()/2;
    pos.y_ = board_->get_columns()-1;
    Piece f(0,'F',pos, movesFox);
    board_->place_piece(f);
}

FaH::~FaH()
{
    //dtor
}
