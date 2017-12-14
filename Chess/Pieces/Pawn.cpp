#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color color, square position) : Piece(color, position) {
    name = "Pawn";
    symbol = "P";
}

/*bool Pawn::isValidMove(square destination) {
    // If pawn is at starting position, it can move two spaces
   
    // Otherwise pawn can only move forward one space
    
    // Pawns can capture diagonally
    
}*/

