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

void Game::display()
{
    std::cout << *board_ << std::endl;
}
