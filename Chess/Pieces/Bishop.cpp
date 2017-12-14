#include "Bishop.hpp"

// Constructor
Bishop::Bishop(Color color, square position) : Piece(color, position) {
    name = "Bishop";
    letter = 'B';
}

