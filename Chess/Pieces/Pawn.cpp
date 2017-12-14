#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color color, square position) : Piece(color, position) {
    name = "Pawn";
    letter = 'P';
}

bool Pawn::isValidMove(vector<vector<Piece*> >* chessboard, square destination) {
    if(position == destination) return false;
    
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);

    // If Pawn is at starting position, it can jump two spaces
    int startRankIndex = color == white ? 1 : 6;
    int jumpRankIndex = color == white ? 3 : 4;
    if(position.first == startRankIndex &&
       destination.first == jumpRankIndex && dx == 0)
        return true;

    if(dx == 0) { // If Pawn is moving forward one step
        if((dy == 1 && color == white) || (dy == -1 && color == black))
            return true;
    } else if(dx == 1 && destinationPiece) { // If Pawn is eating diagonally
        if((dy == 1 && color != destinationPiece->getColor()) || // Can only capture opponent pieces
           (dy == -1 && color != destinationPiece->getColor()))
            return true;
    }

    return false;
}

