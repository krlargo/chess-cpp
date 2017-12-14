#include "Bishop.hpp"

// Constructor
Bishop::Bishop(Color color, square position) : Piece(color, position) {
    name = "Bishop";
    letter = 'B';
}

bool Bishop::isValidMove(square destination) {
    if(position == destination) return false;
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return dx == dy;
}
