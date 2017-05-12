#include "MBT.h"

using namespace std;

vector<pair<Piece,Piece>> MBT::legal_moves(){
    vector<pair<Piece,Piece>> moves;
    return moves;
}

MBT::MBT(int rows, int cols) : Game(rows, cols)
{
    vector<pair<int,int>> movesPlayer1Pawn;
    movesPlayer1Pawn.push_back(make_pair(1,1));
    movesPlayer1Pawn.push_back(make_pair(0,1));
    movesPlayer1Pawn.push_back(make_pair(-1,1));

    vector<pair<int,int>> movesPlayer2Pawn;
    movesPlayer2Pawn.push_back(make_pair(1,-1));
    movesPlayer2Pawn.push_back(make_pair(0,-1));
    movesPlayer2Pawn.push_back(make_pair(-1,-1));

    vector<pair<int,int>> movesPlayer1MegaPawn;
    movesPlayer1MegaPawn.push_back(make_pair(1,1));
    movesPlayer1MegaPawn.push_back(make_pair(0,1));
    movesPlayer1MegaPawn.push_back(make_pair(0,2));
    movesPlayer1MegaPawn.push_back(make_pair(-1,1));

    vector<pair<int,int>> movesPlayer2MegaPawn;
    movesPlayer2MegaPawn.push_back(make_pair(1,-1));
    movesPlayer2MegaPawn.push_back(make_pair(0,-1));
    movesPlayer2MegaPawn.push_back(make_pair(0,-2));
    movesPlayer2MegaPawn.push_back(make_pair(-1,-1));

    Position pos1, pos2;
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos1.x_ = i;
        pos2.x_ = i;
        pos1.y_ = board_->get_rows()-1;
        pos2.y_ = 0;
        Piece p1(0,'M',pos1, movesPlayer1MegaPawn);
        Piece p2(1,'m',pos2, movesPlayer2MegaPawn);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
    for (int i = 0; i < board_->get_columns(); i++)
    {
        pos1.x_ = i;
        pos2.x_ = i;
        pos1.y_ = board_->get_rows()-2;
        pos2.y_ = 1;
        Piece p1(0,'P',pos1, movesPlayer1Pawn);
        Piece p2(1,'p',pos2, movesPlayer2Pawn);
        board_->place_piece(p1);
        board_->place_piece(p2);
    }
}

MBT::~MBT()
{

}


void MBT::start()
{
    MBT *temp = new MBT(board_->get_rows(), board_->get_columns());
    *this = *temp;
}

