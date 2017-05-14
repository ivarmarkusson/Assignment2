#include <iostream>
#include "BT.h"
#include "MBT.h"
#include "FaH.h"

using namespace std;

void list_games();

int main()
{
    Game *game;
    string input;
    int rows = 8;
    int cols = 0;
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
                game = new BT(rows, cols);
                break;
            }
            case(2):
            {
                game = new FaH;
                break;
            }
            case(3):
            {
                game = new MBT(rows, cols);
                break;
            }
            }
        }
        else if(input == "start")
        {
            game->start();
        }
        else if(input == "legal")
        {
            game->legal();
        }
        else if (input == "move")
        {
            game->record_time();
            string from_square,to_square;
            cin >> from_square;
            cin  >> to_square;

            Position from = game->get_int_from_input(from_square);
            Position to = game->get_int_from_input(to_square);

            Piece piece_from = game->get_at_board(from.x_, from.y_);
            Piece piece_to = game->get_at_board(to.x_, to.y_);

            bool validMove = false;

            vector<pair<Piece,Piece>> legal_moves = game->legal_moves();
            for(size_t i = 0; i < legal_moves.size(); i++)
            {
                if(piece_from == legal_moves[i].first && piece_to == legal_moves[i].second)
                {
                    game->move(from_square, to_square);
                    validMove = true;
                }
            }

            if(!validMove)
            {
                cout << "Illegal move" << endl;
            }
        }
        else if(input == "retract")
        {
            game->retract();
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
            game->AI_move();
        }
        else if(input == "level")
        {
            cin >> input;
            if(input == "random")
            {
                game->set_level('r');
            }
            else if (input == "easy")
            {
                game->set_level('e');
            }
            else if (input == "medium")
            {
                game->set_level('m');
            }
            else if (input == "hard")
            {
                game->set_level('h');
            }
        }
        else if (input == "debug")
        {
            debug = true;
        }
        else if (input == "size")
        {
            cin >> rows;
            cin >> cols;
        }
        if (debug)
        {
            game->display();
            cout << game->get_turns() << endl;
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
