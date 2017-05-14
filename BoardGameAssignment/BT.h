#ifndef BT_H
#define BT_H

#include"Game.h"
#include <vector>

class BT : public Game
{
public:
    BT(int rows, int cols = 0);
    virtual ~BT();
    virtual std::vector<std::pair<Piece,Piece>> legal_moves();
    virtual void start();
    virtual int evaluate();
    virtual char terminal_state();
};

#endif // BT_H
