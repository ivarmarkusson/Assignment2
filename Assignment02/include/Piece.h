#ifndef PIECE_H
#define PIECE_H

struct Position
{
    int x_;
    int y_;
};

class Piece
{
    public:
        Piece()
        {
            symbol_ = '.';
            owner_ = -1;
        };
        Piece(int player,char sym,Position pos)
        {
            symbol_ = sym;
            owner_ = player;
            position_.x_ = pos.x_;
            position_.y_ = pos.y_;
        }
        virtual ~Piece() {};
        char get_symbol() {return symbol_;};
        int get_owner() {return owner_;};
        Position get_position() {return position_;};
    protected:
    private:
        char symbol_;
        int owner_;
        Position position_;
};

#endif // PIECE_H
