#include "Knight.hpp"

// Constructor
Knight::Knight(Color color, square position) : Piece(color, position) {
    name = "Knight";
    letter = 'N';
}

bool Knight::isValidMove(square destination) {
    if(position == destination) return false;
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}
