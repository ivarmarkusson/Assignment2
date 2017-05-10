#ifndef BT_H
#define BT_H

#include"Game.h"

class BT : public Game
{
    public:
        BT(int rows, int cols = 0);
        virtual ~BT();
        virtual void initialize_board();
    protected:
    private:
};

#endif // BT_H
