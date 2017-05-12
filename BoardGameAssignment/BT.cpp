#include "BT.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

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
            pos2.x_ = i;
            pos1.x_ = i;
            pos2.y_ = board_->get_rows()-j-1;
            pos1.y_ = j;
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


vector<pair<Piece,Piece>> BT::legal_moves()
{
    int player_turn = turn_ % 2;
    int enemy_turn = abs(turn_%2 - 1);
    Position from;
    Piece current_piece;

    std::vector<std::pair<Piece,Piece>> moves;

    for(int i = 0; i < board_->get_rows(); i++)
    {
        for(int j = 0; j < board_->get_columns(); j++)
        {
            from.x_ = i;
            from.y_ = j;
            current_piece = board_->get_at(from.x_,from.y_);
            if(current_piece.get_owner() == player_turn)
            {
                std::vector<std::pair<int,int>> posible_moves = current_piece.get_posible_moves();
                for(size_t k = 0; k < posible_moves.size(); k++)
                {
                    std::pair<int,int> move = posible_moves[k];
                    int col = from.x_ + move.first;
                    int row = from.y_ + move.second;
                    if(col < board_->get_rows() && col >= 0 && row < board_->get_columns() && col >= 0)
                    {
                        Piece target = board_->get_at(col,row);
                        if(target.get_owner() == -1 || (target.get_owner() == enemy_turn && abs(move.first) == 1))
                        {
                            moves.push_back(std::make_pair(current_piece, target));
                        }
                    }
                }
            }
        }
    }
    return moves;
}

void BT::start()
{
    BT *temp = new BT(board_->get_rows(), board_->get_columns());
    *this = *temp;
}


