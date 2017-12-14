#include "Queen.hpp"

// Constructor
Queen::Queen(Color color, square position) : Piece(color, position), Bishop(color, position), Rook(color, position) {
    Piece::name = "Queen";
    Piece::letter = 'Q';
}

bool Queen::isValidMove(vector<vector<Piece*> >* chessboard, square destination) {
    bool isValidForBishop = Bishop::isValidMove(chessboard, destination);
    bool isValidForRook = Rook::isValidMove(chessboard, destination);
    return isValidForBishop || isValidForRook;
}
