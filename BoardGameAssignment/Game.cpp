#include "Game.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Game::Game(int rows, int cols)
{
    board_ = new Board(rows,cols);
    turn_ = 0;
}

Game::~Game()
{
    delete board_;
    for(size_t i = 0; i < timeline_.size(); i++)
    {
        delete timeline_[i];
    }
}

Piece Game::get_at_board(int x, int y){
    return board_->get_at(x,y);
}

void Game::move(std::string from, std::string to)
{
    Position fromPos, toPos;
    std::string alphabet = "abcdefghi";
    int alphavalueFrom, alphaValueTo;

    if(from.length() == 2 && to.length() == 2)
    {
        if( isdigit(from.at(1)) && isdigit(to.at(1)) )
        {
            if(isalpha(from.at(0)) && isalpha(to.at(0)))
            {
                alphavalueFrom = alphabet.find(from.at(0));
                alphaValueTo = alphabet.find(to.at(0));
                if(   (alphavalueFrom >= 0 && alphavalueFrom < board_->get_columns())
                        && (alphaValueTo >= 0 && alphaValueTo < board_->get_columns()) )
                {
                    fromPos = get_int_from_input(from);
                    toPos = get_int_from_input(to);
                    if(     (fromPos.y_ >= 0 && fromPos.y_ < board_->get_rows())
                            &&  (toPos.y_ >= 0 && toPos.y_ < board_->get_rows()))
                    {
                        if(board_->contains_at(fromPos))
                        {
                            board_->move_from_to(fromPos, toPos);
                        }
                    }
                }
            }
        }
    }
}

Position Game::get_int_from_input(std::string input)
{
    Position pos;
    pos.x_ = input[0] - 97;
    pos.y_ = abs(input[1] - 48 - board_->get_rows());
    return pos;
}

void Game::display() const
{
    board_->display_board();
    std::cout << turn_%2 << std::endl;
}

void Game::retract()
{
    timeline_.pop_back();
    std::cout << "Retract board" << std::endl;
    for (int i = 0; i < timeline_.size();i++)
    {
        timeline_[i]->display_board();
    }
    std::cout << "Retract board end" << std::endl;
    board_ = timeline_[timeline_.size()-1];
}

void Game::record_time()
{
    Board *temp(board_);
    timeline_.push_back(temp);
    std::cout << "Temp board" << std::endl;
    timeline_[timeline_.size()-1]->display_board();
    std::cout << "Temp board end" << std::endl;
}

Position Game::convert_coord(int x, int y)
{
    Position pos;
    pos.x_ = x;
    pos.y_ = abs(y - board_->get_rows()+1);
    return pos;
}
