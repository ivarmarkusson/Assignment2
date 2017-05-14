#ifndef GAME_H
#define GAME_H

#include "Board.h"


class Game
{
public:

    /** \brief initializes the size of the board
     *
     * \param rows for number of rows
     * \param cols for number of columns
     *
     */
    Game(int rows, int cols = 0);

    virtual ~Game();

    /** \brief abstract function to check if a move is legal
     * \return a vector of legal moves for the player whos turn it is
     *
     */
    virtual std::vector<std::pair<Piece,Piece>> legal_moves() = 0;

    /** \brief starts a new instance of the game being played
     *
     */
    virtual void start() = 0;

    /** \brief evaluates the current state of the board
     * \return the state evaluation as an integer
     *
     */
    virtual int evaluate() = 0;

    /** \brief checks to see if the game has hit a terminal state
     * \return a character value to represent the state of the game
     */
    virtual char terminal_state() = 0;

    /** \brief uses legel_moves() to find all legal moves for the player whos turn it is
     */
    void legal();

    /** \brief displays the current game board and info to the console
     *
     */
    void display() const;

    /** \brief moves a piece
     *
     * \param from : start position
     * \param to : end position
     *
     */
    void move(std::string from, std::string to );

    /** \brief moves the game one turn back in time
     *
     */
    void retract();

    /** \brief saves the game so it can be called with retract()
     *
     */
    void record_time();

    /** \brief returns integer value for a string
     *
     * \param input square name e.g. a1
     *
     */
    Position get_int_from_input(std::string input);

    /** \brief find a Piece with specific coordinates
     *
     * \param x coord
     * \param y coord
     * \return Piece with given coordinate
     *
     */
    Piece get_at_board(int x, int y);

    /** \brief Lets the AI move for the player whos turn it is depending on the difficulty
     *
     */
    void AI_move();

    void set_level(char l)
    {
        level_ = l;
    }

    char get_level()
    {
        return level_;
    }

    int get_turns()
    {
        return turn_;
    };

protected:
    Board *board_;
    int turn_;
    std::vector<Board*> timeline_;
    char level_;

private:
    void increase_turn()
    {
        turn_++;
    };
    void decrease_turn()
    {
        turn_--;
    };

    /** \brief minimax search function
     *
     * \param depth : how deep you want to search
     * \return the best move
     */
    std::pair<Piece,Piece> minmax(int depth);

    /** \brief performs minimax search
     *
     * \param depth : how deep you want to search
     * \param move : the move found in minmax()
     * \return evaluation of the state
     *
     */
    int max_move(int depth, std::pair<Piece,Piece> &move);


};

#endif // GAME_H
