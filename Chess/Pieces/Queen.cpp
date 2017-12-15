#include "Queen.hpp"

// Constructor
Queen::Queen(Color color, square position) : Piece(color, position), Bishop(color, position), Rook(color, position) {
    Piece::name = "Queen";
    Piece::letter = 'Q';
}

bool Queen::isValidMove(vector<vector<Piece*> > chessboard, square destination) {
    // Can't stay in place
    if(position == destination) return false;
    
    // Can't capture same colored piece
    int rankIndex = destination.first;
    int fileIndex = destination.second;
    Piece* destinationPiece = chessboard[rankIndex][fileIndex];
    if(destinationPiece && destinationPiece->getColor() == color) return false;
    
    bool isValidForBishop = Bishop::isValidMove(chessboard, destination);
    bool isValidForRook = Rook::isValidMove(chessboard, destination);
    return isValidForBishop || isValidForRook;
}
