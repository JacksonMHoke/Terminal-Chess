CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(game 
    game.cpp board.cpp movement/MovementBehavior.cpp
)