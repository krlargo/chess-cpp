#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color color, square position) : Piece(color, position) {
    name = "Pawn";
    letter = 'P';
}

bool Pawn::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;
    
    int dx = abs(destination.second - position.second);
    int dy = destination.first - position.first; // Don't use abs() because we need to know direction

    // If Pawn is at starting position, it can jump two spaces
    int startRankIndex = color == white ? 1 : 6;
    int jumpRankIndex = color == white ? 3 : 4;
    if(position.first == startRankIndex &&   // Is starting at start position
       destination.first == jumpRankIndex && // Is ending 2 spaces forward
       !destinationPiece && dx == 0)         // Is not capturing or moving horizontally
        return true;

    if(dx == 0 && !destinationPiece) { // If Pawn is moving forward one step
        if((dy == 1 && color == white) || (dy == -1 && color == black))
            return true;
    } else if(dx == 1 && destinationPiece) { // If Pawn is eating diagonally
        if((dy == 1 && color != destinationPiece->getColor()) || // Can only capture opponent pieces
           (dy == -1 && color != destinationPiece->getColor()))
            return true;
    }

    return false;
}

