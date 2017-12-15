#include "King.hpp"

// Constructor
King::King(Color color, square position) : Piece(color, position) {
    name = "King";
    letter = 'K';
}

bool King::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;

    // Can only move 1 square away
    int dx = abs(destination.second - position.second);
    int dy = abs(destination.first - position.first);
    return dx <= 1 && dy <= 1;
}
