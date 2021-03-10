#include "board.hpp"
#include "movement/MovementBehavior.hpp"
#include "pieces/piece.hpp"
#include "BoardFactory.hpp"
#include "ClassicBoardFactory.hpp"
#include "HoardBoardFactory.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::endl;
using std::vector;
using std::cout;
using std::cin;
using std::tolower;

int main () {
    //initialize the board
    BoardFactory* fact;
    Board* b;
    string input;
    
    //ask what type of board to play on
    do {
        cout << "What type of board would you like to play on?\n\ta) classic\n\tb) hoard" << endl;
        cin >> input;
        if (input=="a") {
            fact=new ClassicBoardFactory();
            break;
        } else if (input=="b") {
            fact=new HoardBoardFactory();
            break;
        }
    } while (true);
    //use factory chosen to creat board
    cin.clear();
    b=fact->createBoard();
    char l1,l2,n1,n2;
    //loop while accepting moves and alternating players
    while (input != "quit") {
        //white move
        b->drawBoard('w');
        do {
            cout << "Input quit or white's move in format:\n\tstarting position, ending position\n\tie: a2 a3\n";
            getline(cin, input);
            if (input=="quit") return 0;

            //if input is valid
            if (input[0]<'a' || input[0]>'h' || input[1]<'1' || input[1]>'8' || input[3]<'a' || input[3]>'h' || input[4]<'1' || input[4]>'8') {
                cout << "invalid input" << endl;
                continue;
            }

            //decypher input
            l1=input[0];
            n1=input[1];
            l2=input[3];
            n2=input[4];
            //if piece selected is valid
            if (b->getCell(l1, n1)->getColor()=='b' || !b->getCell(l1,n1)) {
                cout << "Piece selected was of the wrong color or there was no piece at starting position.\n";
                continue;
            }
            //if move goes through break out of this do while
            if (b->getCell(l1,n1)->move(l2, n2)) {
                break;
            }

            cout << "Move entered was not valid due to a piece blocking the way, king being in check after the move, or the piece selected cannot move in the selected way.\n";
        } while (true);

        //black move
        b->drawBoard('w');
        do {
            cout << "Input quit or black's move in format:\n\tstarting position, ending position\n\tie: a2 a3\n";
            getline(cin, input);
            if (input=="quit") return 0;

            //if input is valid
            if (input[0]<'a' || input[0]>'h' || input[1]<'1' || input[1]>'8' || input[3]<'a' || input[3]>'h' || input[4]<'1' || input[4]>'8') {
                cout << "invalid input" << endl;
                continue;
            }

            //decypher input
            l1=input[0];
            n1=input[1];
            l2=input[3];
            n2=input[4];
            //if piece selected is valid
            if (b->getCell(l1, n1)->getColor()=='w' || !b->getCell(l1,n1)) {
                cout << "Piece selected was of the wrong color or there was no piece at starting position.\n";
                continue;
            }
            //if move goes through break out of this do while
            if (b->getCell(l1,n1)->move(l2, n2)) {
                break;
            }

            cout << "Move entered was not valid due to a piece blocking the way, king being in check after the move, or the piece selected cannot move in the selected way.\n";
        } while (true);
    }
}