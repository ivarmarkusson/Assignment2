#include <iostream>
#include "Board.h"
#include <string>
#include <algorithm>
#include "player.h"
#include "BT.h"

using namespace std;

int main()
{

    BT game(8);
    game.display();

    game.initialize_board();
    game.display();

    return 0;
}
