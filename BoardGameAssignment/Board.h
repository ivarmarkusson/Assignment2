#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <ostream>
#include <string>
#include "Player.h"

class Board
{
    public:
        Board(int row, int col = 0);
        Board(const Board& b);
        virtual ~Board();
        void move_from_to(Position from, Position to);
        void place_piece(Piece piece);
        void display_board();
        int get_rows() {return rows_;};
        int get_columns() {return columns_;};
        bool contains_at(Position pos);
        Piece get_at(int x, int y);
        Board& operator=(const Board& rhs);
    protected:
    private:
        int rows_;
        int columns_;
        Piece **board_;
};

#endif // BOARD_H
