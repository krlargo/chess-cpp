#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color color, square position) : Piece(color, position) {
    name = "Pawn";
    letter = 'P';
}

bool Pawn::isValidMove(square destination) {
    if(position == destination) return false;
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);

    // If Pawn is at starting position, it can jump two spaces
    int startRankIndex = color == white ? 1 : 6;
    int jumpRankIndex = color == white ? 3 : 4;
    if(position.first == startRankIndex &&
       destination.first == jumpRankIndex && dx == 0)
        return true;

    // Otherwise Pawns can only move forward one space
    if(dx != 0) return false;
    if((dy == 1 && color == white) || (dy == -1 && color == black)) return true;

    return false;
}

