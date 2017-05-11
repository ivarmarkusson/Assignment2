#include "BT.h"
#include <iostream>
#include <vector>

using namespace std;

BT::BT(int rows, int cols) : Game(rows, cols)
{
    vector<pair<int,int>> movesPlayer1;
    movesPlayer1.push_back(make_pair(1,1));
    movesPlayer1.push_back(make_pair(0,1));
    movesPlayer1.push_back(make_pair(-1,1));

    vector<pair<int,int>> movesPlayer2;
    movesPlayer2.push_back(make_pair(1,-1));
    movesPlayer2.push_back(make_pair(0,-1));
    movesPlayer2.push_back(make_pair(-1,-1));

    Position pos1, pos2;
    for (int i = 0; i < board_->get_columns(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            pos1.x_ = i;
            pos2.x_ = i;
            pos1.y_ = board_->get_rows()-j-1;
            pos2.y_ = j;
            Piece p1(0,'P',pos1, movesPlayer1);
            Piece p2(1,'p',pos2, movesPlayer2);
            board_->place_piece(p1);
            board_->place_piece(p2);
        }
    }
}

BT::~BT()
{
    //dtor
}


vector<pair<Piece,Piece>> BT::legal_moves(){
    vector<pair<Piece,Piece>> moves;
    return moves;
}
