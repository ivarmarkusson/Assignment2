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
    for(int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < columns_; j++)
        {
            board_[i][j].set_position(i,j);
        }
    }

}

Board::Board(const Board& b)
{
    rows_ = b.rows_;
    columns_ = b.columns_;
    board_ = new Piece*[rows_];
    for(int i = 0; i < rows_; i++)
    {
        board_[i] = new Piece[columns_];
        for (int j = 0; j < columns_; j++)
        {
            board_[i][j] = b.board_[i][j];
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

void Board::move_from_to(Position from, Position to)
{
    board_[to.x_][to.y_] = board_[from.x_][from.y_];
    board_[to.x_][to.y_].set_position(to.x_, to.y_);
    board_[from.x_][from.y_] = Piece(from.x_, from.y_);
}

bool Board::contains_at(Position pos)
{
    if(board_[pos.x_][pos.y_].get_owner() != -1)
    {
        return true;
    }
    return false;
}

void Board::place_piece(Piece piece)
{
    Position pos = piece.get_position();
    board_[pos.x_][pos.y_] = piece;
}

void Board::display_board()
{
    std::string alpha ("abcdefghi");
    for (int i = rows_-1; i >= 0; i--)
    {
        std::cout << i+1 << " ";
        for (int j = 0; j < columns_; j++)
        {
            std::cout  <<  board_[j][i].get_symbol() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int i = 0; i < columns_; i++)
    {
        std::cout << alpha[i] << " ";
    }
    std::cout << std::endl;
}

Piece Board::get_at(int x, int y)
{
    return board_[x][y];
}

Board& Board::operator=(const Board& rhs)
{
    if (this != &rhs)
    {
        Piece **temp = new Piece*[rows_];
        for (int i = 0; i < rows_; i++)
        {
            delete [] board_[i];
            temp[i] = new Piece[rows_];
        }
        delete [] board_;

        for(int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < columns_; j++)
            {
                temp[i][j] = rhs.board_[i][j];
            }
        }
        board_ = temp;
    }
    return *this;
}

int Board::count_pieces_for_owner(int owner)
{
    int counter = 0;
    for(int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < columns_; j++)
        {
            if (board_[i][j].get_owner() == owner)
            {
                counter++;
            }
        }
    }
    return counter;
}
