#include "Bishop.hpp"

// Constructor
Bishop::Bishop(Color color, square position) : Piece(color, position) {
    name = "Bishop";
    letter = 'B';
}

bool Bishop::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;
    
    // Make sure position is on the diagonal
    int dx = destination.second - position.second;
    int dy = destination.first - position.first;
    if(abs(dx) != abs(dy)) return false; // dx should equal dy
    
    // Check that no other pieces are blocking it
    // Get unit vector; should be either 1,-1, or 0
    int dxUnit = dx/abs(dx);
    int dyUnit = dy/abs(dy);
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
