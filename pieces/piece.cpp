#include "piece.hpp"
#include "../movement/MovementBehavior.hpp"

Piece::~Piece() {
    for (auto mb : moveB) {
        delete mb;
    }
}