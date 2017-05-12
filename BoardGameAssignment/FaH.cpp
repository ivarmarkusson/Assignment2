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
        pos.y_ = board_->get_columns()-1;
        Piece h(1,'H', pos, movesHound);
        board_->place_piece(h);
    }
    pos.x_ = board_->get_columns()/2;
    pos.y_ = 0;
    Piece f(0,'F',pos, movesFox);
    board_->place_piece(f);
}

FaH::~FaH()
{
    //dtor
}

vector<pair<Piece,Piece>> FaH::legal_moves()
{
    /*
    int player_turn = turn_ % 2;
    Position from;
    Piece current_piece;
    vector<pair<Piece,Piece>> moves;

    for(int i = 0; i < board_->get_rows(); i++)
    {
        for(int j = 0; j < board_->get_columns(); j++)
        {
            from = convert_coord(i,j);
            current_piece = board_->get_at(from.x_,from.y_);
            if(current_piece.get_owner() == player_turn)
            {
                vector<pair<int,int>> posible_moves = current_piece.get_posible_moves();
                for(size_t k = 0; k < posible_moves.size(); k++)
                {
                    pair<int,int> move = posible_moves[k];
                    int row = from.x_ + move.first;
                    int col = from.y_ + move.second;
                    if(row < board_->get_rows() && row >= 0 && col < board_->get_columns() && col >= 0)
                    {
                        Piece target = board_->get_at(row,col);
                        if(target.get_owner() == -1)
                        {
                            moves.push_back(make_pair(current_piece, target));
                        }
                    }
                }
            }
        }
    }

    return moves;
*/
}


void FaH::start()
{
    FaH *temp = new FaH;
    *this = *temp;
}
