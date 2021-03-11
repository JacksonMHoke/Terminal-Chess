CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(game 
    game.cpp board.cpp movement/MovementBehavior.cpp pieces/piece.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp board.cpp movement/MovementBehavior.cpp pieces/piece.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE	gtest_disable_pthreads=ON)