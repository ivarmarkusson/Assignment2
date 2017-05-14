#ifndef PIECE_H
#define PIECE_H

#include <vector>

struct Position
{
    int x_;
    int y_;
};

class Piece
{
    public:
        /** \brief default constroctor for Piece
         *
         * sets owner as -1 and symbol as .
         *
         */
        Piece();

        /** \brief constructor to initilaze a location for piece
         *
         * \param x coord
         * \param y coord
         *
         */
        Piece(int x, int y);

        /** \brief constructor for advanced Pieces
         *
         * \param player to give the Piece an owner.
         * \param sym to set the symbol for the piece.
         * \param Position to set the position of the Piece.
         * \param a vector of moves to give the piece legal moves.
         * \return
         *
         */
        Piece(int player,char sym,Position pos, std::vector<std::pair<int,int>> moves);

        virtual ~Piece();

        char get_symbol() const {return symbol_;}

        int get_owner() const {return owner_;}

        Position get_position() const {return position_;}

        void set_position(int x, int y);

        std::vector<std::pair<int,int>> get_posible_moves() const {return posible_moves_;}

    private:
        bool operator== (const Piece& rhs ) const;
        char symbol_;
        int owner_;
        Position position_;
        std::vector<std::pair<int,int>> posible_moves_;
};

#endif // PIECE_H
