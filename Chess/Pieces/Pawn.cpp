#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "Pawn";
    symbol = "P";
}
