#include "King.hpp"

// Constructor
King::King(Color color, square position) : Piece(color, position) {
    name = "King";
    letter = 'K';
}

bool King::isValidMove(vector<vector<Piece*> >* chessboard, square destination) {
    if(position == destination) return false;
    int dy = abs(destination.first - position.first);
    int dx = abs(destination.second - position.second);
    return dx <= 1 && dy <= 1;
}
