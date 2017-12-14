#include "Rook.hpp"

// Constructor
Rook::Rook(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "Rook";
    symbol = "R";
}

