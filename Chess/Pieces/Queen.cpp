#include "Queen.hpp"

// Constructor
Queen::Queen(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "Queen";
    symbol = "Q";
}

