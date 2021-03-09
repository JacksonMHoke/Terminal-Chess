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

    b->getCell('d','2')->move('d','3');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '3')->move('d','4');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '4')->move('d','5');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '5')->move('d','6');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '6')->move('e','7');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '1')->move('d', '5');

    b->drawBoard('w');
    cout << endl;

    b->getCell('d', '5')->move('h', '5');

    b->drawBoard('w');
    cout << endl;

    b->getCell('h', '5')->move('f', '3');

    b->drawBoard('w');
    cout << endl;

    b->getCell('b', '1')->move('c', '3');
    b->drawBoard('w');
    cout << endl;

    b->getCell('e', '1')->move('e', '2');
    b->drawBoard('w');
    cout << endl;
}