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
    
    //ask what type of board to play on
    do {
        cout << "What type of board would you like to play on?\n\ta) classic\n\tb) hoard" << endl;
        string input;
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

    b=fact->createBoard();

    b->drawBoard('w');
    cout << endl;

    b->getCell('e','2')->move('e','3');

    b->drawBoard('w');
    cout << endl;

    b->getCell('e', '3')->move('e','4');

    b->drawBoard('w');
    cout << endl;

    b->getCell('e', '4')->move('e','5');

    b->drawBoard('w');
    cout << endl;

    b->getCell('e', '5')->move('e','6');

    b->drawBoard('w');
    cout << endl;

    b->getCell('e', '6')->move('f','7');

    b->drawBoard('w');
    cout << endl;
}