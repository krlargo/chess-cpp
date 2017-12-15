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
    
    // Make sure position is horizontal or vertical
    int dx = abs(destination.second - position.second);
    int dy = abs(destination.first - position.first);
    if((dx != 0) && (dy != 0)) return false; // Either dx or dy must be 0
    
    // Check that no other pieces are blocking it
    // Get unit vector; should be either 1,-1, or 0
    int dxUnit = (dx ? (dx/abs(dx)) : 0);
    int dyUnit = (dy ? (dy/abs(dy)) : 0);
    // Start at next square towards destination
    int x = position.second + dxUnit;
    int y = position.first + dyUnit;
    // Iterate one square at a time
    while(x != destination.second && y != destination.first) {
        // If a piece is blocking, move is invalid
        if(chessboard[y][x]) return false;
        // Increment one square at a time
        x += dxUnit;
        y += dyUnit;
    }
    
    return true;
}
