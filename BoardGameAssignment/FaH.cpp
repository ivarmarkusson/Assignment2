#include "FaH.h"
#include <vector>
#include <iostream>

FaH::FaH() : Game(8)
{
    std::vector<std::pair<int,int>> movesHound;
    movesHound.push_back(std::make_pair(1,-1));
    movesHound.push_back(std::make_pair(-1,-1));

    std::vector<std::pair<int,int>> movesFox;
    movesFox.push_back(std::make_pair(1,1));
    movesFox.push_back(std::make_pair(-1,1));
    movesFox.push_back(std::make_pair(1,-1));
    movesFox.push_back(std::make_pair(-1,-1));

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

int FaH::evaluate()
{
    int player = turn_ % 2;
    char terminal_status = terminal_state();

    if(player == 0)
    {
        switch(terminal_status)
        {
        case('w'):
        {
            return 100;
        }
        case('l'):
        {
            return 0;
        }
        case('t'):
        {
            return 50;
        }
        }

    }
    else
    {
        switch(terminal_status)
        {
        case('w'):
        {
            return 0;
        }
        case('l'):
        {
            return 100;
        }
        case('t'):
        {
            return 50;
        }
        }
    }
    return 0;
}

char FaH::terminal_state()
{
    for(int i = 0; i < board_->get_rows(); i++)
    {
        for(int j = 0; j < board_->get_columns(); j++)
        {
            Piece obj = board_->get_at(i,j);
            if( (i == board_->get_rows() -1) && obj.get_symbol() == 'F' )
            {
                return 'w'; //fox won
            }
        }
    }
    if(legal_moves().empty() && (turn_ % 2) == 0)
    {
        return 'l'; //hound won
    }
    if(legal_moves().empty())
    {
        return 't'; // tie
    }
    return 'n'; // not terminal
}

std::vector<std::pair<Piece,Piece>> FaH::legal_moves()
{
    int player_turn = turn_ % 2;
    Position from;
    Piece current_piece;

    std::vector<std::pair<Piece,Piece>> moves_;
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
                    int row = from.x_ + move.first;
                    int col = from.y_ + move.second;
                    if(row < board_->get_rows() && row >= 0 && col < board_->get_columns() && col >= 0)
                    {
                        Piece target = board_->get_at(row,col);
                        if(target.get_owner() == -1)
                        {
                            moves_.push_back(std::make_pair(current_piece, target));
                        }
                    }
                }
            }
        }
    }
    return moves_;
}

void FaH::start()
{
    FaH *temp = new FaH;
    *this = *temp;
}
