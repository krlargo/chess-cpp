#include "Queen.hpp"

// Constructor
Queen::Queen(Color color, square position) : Piece(color, position), Bishop(color, position), Rook(color, position) {
    Piece::name = "Queen";
    Piece::letter = 'Q';
}

bool Queen::isValidMove(square destination) {
    bool isValidForBishop = Bishop::isValidMove(destination);
    bool isValidForRook = Rook::isValidMove(destination);
    return isValidForBishop || isValidForRook;
}
