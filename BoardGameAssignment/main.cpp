#include <iostream>
#include "Board.h"
#include "BT.h"
#include "MBT.h"
#include "FaH.h"

using namespace std;

void list_games();

int main()
{
    Game *game;
    string input;
    bool debug = false;
    while(input != "quit")
    {
        cin >> input;
        if(input == "list")
        {
            list_games();
        }
        else if (input == "game")
        {
            int choice;
            cin >> choice;
            switch(choice)
            {
                case(1):
                {
                    game = new BT(8);
                    break;
                }
                case(2):
                {
                    game = new FaH;
                    break;
                }
                case(3):
                {
                    game = new MBT(8);
                    break;
                }
            }
        }
        else if(input == "start")
        {

        }
        else if(input == "legal")
        {

        }
        else if (input == "move")
        {
            game->record_time();
            string from_square,to_square;
            cin >> from_square;
            cin >> to_square;
            game->move(from_square, to_square);
            if(debug)
            {
                game->display();
            }
            game->increase_turn();
        }
        else if(input == "retract")
        {
            game->retract();
            game->decrease_turn();
        }
        else if(input == "display")
        {
            game->display();
        }
        else if (input == "evaluate")
        {

        }
        else if(input == "go")
        {
            game->increase_turn();
        }
        else if(input == "level")
        {

        }
        else if (input == "debug")
        {
            debug = true;
        }
    }
    return 0;
}

void list_games()
{
    cout << "1. Breakthrough" << endl;
    cout << "2. Fox and Hounds" << endl;
    cout << "3. Mega-Breaktrough" << endl;
}
