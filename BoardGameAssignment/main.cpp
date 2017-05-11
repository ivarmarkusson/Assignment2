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

            Position from = game->get_int_from_input(from_square);
            Position to = game->get_int_from_input(to_square);

            Position pos_from = game->convert_coord(from.x_, from.y_);
            Position pos_to = game->convert_coord(to.x_, to.y_);

            Piece piece_from = game->get_at_board(pos_from.x_, pos_from.y_);
            Piece piece_to = game->get_at_board(pos_to.x_, pos_to.y_);

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
