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
        void move_from_to(std::string from, std::string to);
        void get_int_from_input(int& val1, int& val2, std::string input);
        void place_piece(Piece piece);
        friend std::ostream& operator<<(std::ostream& os, const Board& board);
        int get_rows() {return rows_;};
        int get_columns() {return columns_;};
    protected:
    private:
        int rows_;
        int columns_;
        Piece **board_;
};

#endif // BOARD_H
