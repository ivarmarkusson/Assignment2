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
        virtual ~Board();
        void move_from_to(Position from, Position to);
        void place_piece(Piece piece);
        void display_board();
        int get_rows() {return rows_;};
        int get_columns() {return columns_;};
        bool contains_at(Position pos);
    protected:
    private:
        int rows_;
        int columns_;
        Piece **board_;
};

#endif // BOARD_H