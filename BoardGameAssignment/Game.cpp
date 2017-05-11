#include "Game.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Game::Game(int rows, int cols)
{
    board_ = new Board(rows,cols);
}

Game::~Game()
{
    delete board_;
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
}
