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

    b->getCell('e','7')->move('e','6');
    b->drawBoard('w');

    b->getCell('h','2')->move('h','3');
    b->drawBoard('w');

    b->getCell('h','3')->move('h','4');
    b->drawBoard('w');

    b->getCell('a','2')->move('a','3');
    b->drawBoard('w');

    if (!b->getCell('d','8')->move('h','4'))  cout << "invalid move!" << endl;
    b->drawBoard('w');

    if (!b->getCell('g','2')->move('g','3')) cout << "invalid move!" << endl;
    b->drawBoard('w');

    b->getCell('g','3')->move('h','4');
    b->drawBoard('w');
}