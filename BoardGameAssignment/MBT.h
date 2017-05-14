#ifndef MBT_H
#define MBT_H

#include "Game.h"
#include <vector>

class MBT : public Game
{
public:
    MBT(int rows, int cols = 0);
    virtual ~MBT();
    virtual std::vector<std::pair<Piece,Piece>> legal_moves();
    virtual void start();
    virtual int evaluate();
    virtual char terminal_state();
};

#endif // MBT_H
