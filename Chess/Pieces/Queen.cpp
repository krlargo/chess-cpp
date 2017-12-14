#include "Queen.hpp"

// Constructor
Queen::Queen(Color color, square position) : Piece(color, position) {
    name = "Queen";
    letter = 'Q';
}

