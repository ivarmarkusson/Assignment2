#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <ostream>
#include <string>

class Board
{
public:
    /** \brief Constructor for Board
     * \param row initializes rows
     * \param col initializes columns, if left empty it will be set to the same as rows
     */
    Board(int row, int col = 0);

    /** \brief copy constructor for Board
     *
     * \param b the board to be copied
     *
     */
    Board(const Board& b);
    virtual ~Board();

    /** \brief moves a piece on the board
     *
     * \param Position from, start position
     * \param Position to, end position
    */
    void move_from_to(Position from, Position to);

    /** \brief Places a piece on the board.
     *
     * \param Piece piece, the piece to be placed
     *
     */
    void place_piece(Piece piece);

    /**
     *\brief Displays the board to the console.
     */
    void display_board();

    int get_rows()
    {
        return rows_;
    };

    int get_columns()
    {
        return columns_;
    };

    /** \brief Check if the board contains a Piece owned by a player
     *
     * \param Position pos, position of the piece
     * \return true if a player owns a piece on the given position
     *   otherwise returns false
     *
     */
    bool contains_at(Position pos);

    /** \brief returns a Piece at the position that is asked for
     *
     * \param x coord.
     * \param y coord.
     * \return The piece on the position asked for
     *
     */
    Piece get_at(int x, int y);

    Board& operator=(const Board& rhs);

    /** \brief Counts the pieces on the board for an owner.
     *
     * \param int owner, the owner of which pieces should be counted
     * \return the number of pieces the owner has on the board.
     *
     */
    int count_pieces_for_owner(int owner);
private:
    int rows_;
    int columns_;
    Piece **board_;
};

#endif // BOARD_H
