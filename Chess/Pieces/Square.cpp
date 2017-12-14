#include "Square.hpp"

Square::Square(char rank, char file, Piece* piece) {
    this->rank = rank;
    this->file = file;
    this->piece = piece;
}

char Square::getRank() { return rank; }
char Square::getFile() { return file; }

Square* Square::getAboveSq() { return up; }
Square* Square::getBelowSq() { return down; }
Square* Square::getLeftSq() { return left; }
Square* Square::getRightSq() { return right; }

void Square::setAboveSq(Square* sq) { up = sq; }
void Square::setBelowSq(Square* sq) { down = sq; }
void Square::setLeftSq(Square* sq) { left = sq; }
void Square::setRightSq(Square* sq) { right = sq; }
