#include "Knight.hpp"

// Constructor
Knight::Knight(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "Knight";
    symbol = "N";
}

