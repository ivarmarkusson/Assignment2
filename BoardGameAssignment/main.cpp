#include <iostream>
#include "Board.h"
#include <string>
#include <algorithm>
#include "player.h"
#include "BT.h"
#include "Piece.h"

using namespace std;

int main()
{
    BT game(8);
    game.display();

    game.initialize_board();
    game.display();

/*
    Board board(8);
    cout << "Empty board" << endl;
    cout << board << endl << endl;

    Position pos;
    pos.x_ = 0;
    pos.y_ = 0;
    Piece p(0,'P', pos);

    board.place_Piece(p);
    cout << board << endl;

    board.move_from_to("a8", "a7");
    cout << board << endl;
*/
    return 0;
}
