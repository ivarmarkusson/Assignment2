#include "MBT.h"
#include "stdlib.h"
#include <iostream>

MBT::MBT(int rows, int cols) : Game(rows, cols)
{
    std::vector<std::pair<int,int>> movesPlayer1Pawn;
    movesPlayer1Pawn.push_back(std::make_pair(1,1));
    movesPlayer1Pawn.push_back(std::make_pair(0,1));
    movesPlayer1Pawn.push_back(std::make_pair(-1,1));

    std::vector<std::pair<int,int>> movesPlayer2Pawn;
    movesPlayer2Pawn.push_back(std::make_pair(1,-1));
    movesPlayer2Pawn.push_back(std::make_pair(0,-1));
    movesPlayer2Pawn.push_back(std::make_pair(-1,-1));

    std::vector<std::pair<int,int>> movesPlayer1MegaPawn;
    movesPlayer1MegaPawn.push_back(std::make_pair(1,1));
    movesPlayer1MegaPawn.push_back(std::make_pair(0,1));
    movesPlayer1MegaPawn.push_back(std::make_pair(0,2));
    movesPlayer1MegaPawn.push_back(std::make_pair(-1,1));

    std::vector<std::pair<int,int>> movesPlayer2MegaPawn;
    movesPlayer2MegaPawn.push_back(std::make_pair(1,-1));
    movesPlayer2MegaPawn.push_back(std::make_pair(0,-1));
    movesPlayer2MegaPawn.push_back(std::make_pair(0,-2));
    movesPlayer2MegaPawn.push_back(std::make_pair(-1,-1));

    Position pos1, pos2;
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos2.x_ = i;
        pos1.x_ = i;
        pos2.y_ = board_->get_rows()-1;
        pos1.y_ = 0;
        Piece p1(0,'M',pos1, movesPlayer1MegaPawn);
        Piece p2(1,'m',pos2, movesPlayer2MegaPawn);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos2.x_ = i;
        pos1.x_ = i;
        pos2.y_ = board_->get_rows()-2;
        pos1.y_ = 1;
        Piece p1(0,'P',pos1, movesPlayer1Pawn);
        Piece p2(1,'p',pos2, movesPlayer2Pawn);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
}

MBT::~MBT()
{

}

char MBT::terminal_state(){
    for(int i = 0; i < board_->get_columns(); i++){
        if(board_->get_at(i,0).get_owner() == 1){
            return 'l'; // Player 2 wins
        }
        if(board_->get_at(i,board_->get_rows()-1).get_owner() == 0){
            return 'w'; // Player 1 wins
        }
    }
    if(legal_moves().empty()){
        return 't'; // tie
    }

    return 'n'; // not a terminal state
}

int MBT::evaluate(){
    return 0;
}

std::vector<std::pair<Piece,Piece>> MBT::legal_moves()
{
    int player_turn = turn_ % 2;
    int enemy_turn = abs(player_turn -1);
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
                    int col = from.x_ + move.first;
                    int row = from.y_ + move.second;
                    if(row < board_->get_rows() && row >= 0 && col < board_->get_columns() && col >= 0)
                    {
                        Piece target = board_->get_at(col,row);
                        if( (target.get_owner() == -1 && abs(move.second) == 1) || ( target.get_owner() == enemy_turn && abs(move.first) == 1) )
                        {
                            moves_.push_back(std::make_pair(current_piece, target));
                        }
                        else if(current_piece.get_symbol() == 'm')
                        {
                            if(move.second == -2)
                            {
                                if( (board_->get_at(col,row +1).get_owner() == -1) && (target.get_owner() == -1) )
                                {
                                    moves_.push_back(std::make_pair(current_piece, target));
                                }
                            }
                        }
                        else if(current_piece.get_symbol() == 'M')
                        {
                            if(move.second == 2)
                            {
                                if( (board_->get_at(col,row -1).get_owner() == -1) && (target.get_owner() == -1) )
                                {
                                    moves_.push_back(std::make_pair(current_piece, target));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return moves_;
}

void MBT::start()
{
    MBT *temp = new MBT(board_->get_rows(), board_->get_columns());
    *this = *temp;
}
