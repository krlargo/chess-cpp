#include "Bishop.hpp"

// Constructor
Bishop::Bishop(Color color, int rankIndex, int fileIndex) : Piece(color, rankIndex, fileIndex) {
    name = "Bishop";
    symbol = "B";
}

