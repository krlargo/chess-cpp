#include "King.hpp"

// Constructor
King::King(Color color, square position) : Piece(color, position) {
    name = "King";
    letter = 'K';
}

