#include "Rook.hpp"

// Constructor
Rook::Rook(Color color, square position) : Piece(color, position) {
    name = "Rook";
    letter = 'R';
}

bool Rook::isValidMove(vector<vector<Piece*> >* chessboard, square destination) {
    if(position == destination) return false;
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return (dx != 0) !=  (dy != 0); // XOR: One of the translations should be 0
}
