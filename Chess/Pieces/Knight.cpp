#include "Knight.hpp"

// Constructor
Knight::Knight(Color color, square position) : Piece(color, position) {
    name = "Knight";
    letter = 'N';
}

bool Knight::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;

    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;
    
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}
