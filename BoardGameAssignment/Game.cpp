#include "Game.h"
#include <iostream>

Game::Game(int rows, int cols)
{
    board_ = new Board(rows,cols);
}

Game::~Game()
{
    delete board_;
}

void Game::display() const
{
    board_->display_board();
}
