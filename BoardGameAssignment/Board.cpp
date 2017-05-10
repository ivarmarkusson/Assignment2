#include "Board.h"
#include <iostream>
#include <string>
#include <cstdlib>


Board::Board(int row, int col) : rows_(row), columns_(col)
{
    if(columns_ == 0)
        columns_ = rows_;
    if (rows_ >= columns_)
    {
        board_ = new Piece*[rows_];
        for (int i = 0; i < rows_; i++)
        {
            board_[i] = new Piece[rows_];
        }
    }
    else
    {
        board_ = new Piece*[columns_];
        for (int i = 0; i < columns_; i++)
        {
            board_[i] = new Piece[rows_];
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < rows_; i++)
    {
        delete [] board_[i];
    }
    delete [] board_;
}

void Board::move_from_to(Piece from, Piece to)
{
    board_[to.get_position().x_][to.get_position().y_] = board_[from.get_position().x_][from.get_position().y_];
    board_[from.get_position().x_][from.get_position().y_] = Piece();

    /*
    int from_x = 0,from_y = 0;
    int to_x = 0, to_y = 0;
    get_int_from_input(from_x,from_y, from);
    get_int_from_input(to_x, to_y, to);

    board_[to_x][to_y] = board_[from_x][from_y];
    board_[from_x][from_y] = Piece();
    */
}

void Board::get_int_from_input(int& val1, int& val2, std::string input)
{
    val1 = input[0] - 97;
    val2 = abs(input[1] - 48 - rows_);
}

void Board::place_piece(Piece piece)
{
    Position pos = piece.get_position();
    board_[pos.x_][pos.y_] = piece;
}

/**
 * Displays the board to the console
 * ONLY use if you want to display on the console
 */

void Board::display_board()
{
    std::string alpha ("abcdefghi");
    for (int i = 0; i < rows_; i++)
    {
        std::cout << rows_- i;
        for (int j = 0; j < columns_; j++)
        {
            std::cout << board_[j][i].get_symbol();
        }
        std::cout << std::endl;
    }
    std::cout << " ";
    for (int i = 0; i < columns_; i++)
    {
        std::cout << alpha[i];
    }
    std::cout << std::endl;
}
