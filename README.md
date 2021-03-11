# Chess
 
 > Authors: \<[Jackson Hoke](https://github.com/JacksonMHoke)\>
 > \<[Grace Lee](https://github.com/glee139)\>
 > \<[Woovin Youn](https://github.com/groovinwoovin)\>

## Project Description
 > For our project we are making a pvp chess game where you can move your pieces through the terminal(if we have time we will try to add an interface to play through). We all enjoy playing games and chess seemed interesting to make one that seemed feasible and relatable. We will be using C++ as our main coding language. As for external libraries, at this moment we do not plan on using any. 
## Input/Output
 >The player input will be the chess moves through the terminal(with mouse if we have time). More specifically, the input will be entered in by a coordinate system that is used in chess with the horizontal being represented by a-h and the vertical coordinate being represented by 1-8. The coordinates start at the white side's left rook(ie. A1). The output will be the board through terminal using different letters to represent the pieces(board graphics if we have time).
## Design Patterns
 > For one of our design patterns we chose to use the Strategy Design Pattern. We picked this design pattern because there are many different behaviors in the game that are shared between the pieces such as checking, moving, and illegal moves. More specifically some pieces share the same functionality as others(for example the queen is a bishop and a rook movement wise) and also when a pawn promotes, it's movement changes to the movement behavior of a different piece. This makes the strategy pattern a good fit as we will be able to swap behaviors and also combine different behaviors as we see fit, which will allow us to implement the features such as the case with the pawn and the queen easier. This will allow us to prevent running across problems when pawns promote and repetitive code with the queen movement.
 
 > For the second design pattern we chose to use the Factory Method pattern. We will use the Factory Method class to create the different pieces at the beginning of the game. After designing the basic chess game, we want to implement different variants of it and anticipated on having to hard code for each variant within the Game class. But with the Factory Method class, we can implement each type of variant as its own class and inherit from a base factory class.

## Class Diagram
![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/Chess_Diagram.png)

 ## Screenshots
 > This is choosing which type of board to set up.\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/input1.png)\
 > This is a picture of the set up classic board chosen from part 1\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/board10.png)\
 > This is a picture of the input instructions given when inputting a move for white\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/input2.png)\
 > This is a picture of an example move typed into the terminal\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/input3.png)\
 > This is a picture of the board after that example move was executed\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/board20.png)\
 > This is a picture of the input instructions for blacks turn\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/input4.png)\
 > This is a picture of the input instructions when an invalid move is inputted\
 > ![Image of Yaktocat](https://github.com/cs100/final-project-wyoun005-glee139-jhoke001/blob/master/screenshots/input5.png)
 ## Installation/Usage
 > Open terminal and run 
 > ```
 > git clone --recurse-submodules https://github.com/cs100/final-project-wyoun005-glee139-jhoke001.git
 > ```
 > git clone will copy the files from this git repository onto your computer\
 > Then run:
 > ```
 > cd final-project-wyoun005-glee139-jhoke001/
 > ```
 > This will navigate to the folder you just downloaded\
 > Then run:
 > ```
 > cmake3 .
 > make
 > ```
 > To launch the game run\
 > ```
 > ./game
 > ```
 > Enjoy!\
 ## Usage
 This game is a local 2p terminal chess game that continues until one player gets checkmated.(checkmate not implemented yet)\
 Select which board you want to set up by typing a or b(a for classic, b for hoard)\
 Asterisks are empty empty spots on the board, capital letters are white pieces and lowercase letters are black pieces.
 To move a piece, type in the starting position(ie. a2) followed by a space and then the ending position(ie. a3)\
  For example: "b2 b3" moves the pawn on b2 to b3 on a classic board.\
  columns are labeled a-h, and rows are labeled 1-8 starting at the bottom left\
  When you want to exit, type quit.
 ## Testing
 > We used google test to test our code. We tested each function seperately for boundary cases and normal functionality and played a game of chess all the way through to see if it worked. We ran valgrind to make sure that there were no memory leaks. We tested our code by going through the board class like we do in the game.cpp file. We accessed functions like getCell and addPiece and used the piece getter functions to check whether the move went well.
 
