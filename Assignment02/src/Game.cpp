#include "Game.h"
#include <iostream>
#include "Piece.h"

Game::Game(int rows, int cols)
{
    board_ = new Board(rows,cols);
}

Game::~Game()
{
    delete board_;
}

void Game::move(Piece from, Piece to){
    Position posFrom = from.get_position();
    Position posTo = to.get_position();


}

void Game::display()
{
    std::cout << *board_ << std::endl;
}
