#include "Rook.hpp"

// Constructor
Rook::Rook(Color color, square position) : Piece(color, position) {
    name = "Rook";
    letter = 'R';
}

bool Rook::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;
    
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return (dx != 0) !=  (dy != 0); // XOR: One of the translations should be 0
}
