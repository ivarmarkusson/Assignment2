#include "Game.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

Game::Game(int rows, int cols)
{
    board_ = new Board(rows,cols);
    turn_ = 0;
    timeline_.clear();
    level_ = 'r';
}

Game::~Game()
{
    delete board_;
    for(size_t i = 0; i < timeline_.size(); i++)
    {
        delete timeline_[i];
    }
}

Piece Game::get_at_board(int x, int y)
{
    return board_->get_at(x,y);
}

void Game::move(std::string from, std::string to)
{
    increase_turn();
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
    pos.y_ = input[1] - 49;
    return pos;
}

void Game::display() const
{
    board_->display_board();
    std::cout << turn_%2 << std::endl;
    std::cout << board_->count_pieces_for_owner(0) << " "
              << board_->count_pieces_for_owner(1) << std::endl;
}

void Game::retract()
{
    if(timeline_.empty())
    {
        return;
    }
    board_ = timeline_[timeline_.size()-1];
    timeline_.pop_back();
    decrease_turn();
}

void Game::record_time()
{
    Board *temp = new Board(*board_);
    timeline_.push_back(temp);
}

void Game::legal()
{
    std::vector<std::pair<Piece,Piece>> moves = legal_moves();
    char fromX, toX;
    int fromY, toY;
    std::cout << "legal moves" << std::endl;
    for(size_t i = 0; i < moves.size(); i++)
    {
        fromX = moves[i].first.get_position().x_ + 97;
        fromY = moves[i].first.get_position().y_ + 1;
        toX = moves[i].second.get_position().x_ + 97;
        toY = moves[i].second.get_position().y_ + 1;
        std::cout << "From: (" << fromX << ", " << fromY << ") ->";
        std::cout << "To: (" << toX << ", " << toY  << ")" << std::endl;
    }
}

void Game::AI_move()
{
    Position from;
    Position to;
    if(level_ == 'r')
    {
        int random = 0;
        srand(time(0));
        std::vector<std::pair<Piece,Piece>> moves = legal_moves();
        random = (rand() % moves.size());
        std::cout << "random number: " << random << std::endl;
        std::cout << "moves.size: " << moves.size() << std::endl;
        from = moves.at(random).first.get_position();
        to = moves.at(random).second.get_position();
        board_->move_from_to(from, to);
        increase_turn();
    }
}
