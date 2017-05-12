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
            game->start();
        }
        else if(input == "legal")
        {

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
            for(size_t i = 0; i < legal_moves.size(); i++){
                if(piece_from == legal_moves[i].first && piece_to == legal_moves[i].second){
                    game->move(from_square, to_square);
                    validMove = true;
                }
            }

            if(!validMove){
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

        }
        else if(input == "level")
        {
            cin >> input;
            if(input == "random")
            {

            }
            else if (input == "easy")
            {

            }
            else if (input == "medium")
            {

            }
            else if (input == "hard")
            {

            }
        }
        else if (input == "debug")
        {
            debug = true;
        }
        if (debug)
        {
            game->display();
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
