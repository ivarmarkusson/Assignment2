#ifndef FAH_H
#define FAH_H

#include "Game.h"

class FaH : public Game
{
    public:
        FaH();
        virtual ~FaH();
        virtual std::vector<std::pair<Piece,Piece>> legal_moves();
        virtual int evaluate();
        virtual void start();
        virtual char terminal_state();

    protected:
    private:
};

#endif // FAH_H
