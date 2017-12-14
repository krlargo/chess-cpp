#include "King.hpp"

// Constructor
King::King(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "King";
    symbol = "K";
}

