#ifndef FAH_H
#define FAH_H

#include "Game.h"

class FaH : public Game
{
    public:
        FaH();
        virtual ~FaH();
        virtual std::vector<std::pair<Piece,Piece>> legal_moves();
    protected:
    private:
};

#endif // FAH_H
