#include "Piece.h"

using namespace std;

Piece::Piece()
{
    symbol_ = '.';
    owner_ = -1;
}

Piece::Piece(int player,char sym,Position pos, vector<std::pair<int,int> > moves)
{
    posible_moves_ = moves;
    symbol_ = sym;
    owner_ = player;
    position_.x_ = pos.x_;
    position_.y_ = pos.y_;
}

Piece::~Piece()
{

}

void Piece::set_position(int x, int y)
{
    position_.x_ = x;
    position_.y_ = y;
}

bool Piece::operator== (const Piece& rhs) const
{
    if(get_symbol() == rhs.get_symbol()){
        if(get_owner() == rhs.get_owner()){
            if(get_position().x_ == rhs.get_position().x_ && get_position().y_ == rhs.get_position().y_){
                if(get_posible_moves().size() == rhs.get_posible_moves().size()){
                    for(size_t i = 0; i < posible_moves_.size(); i++){
                        if( (posible_moves_[i].first != rhs.get_posible_moves()[i].first) ||
                            (posible_moves_[i].second != rhs.get_posible_moves()[i].second) ){
                            return false;
                        }
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

    return true;
}
