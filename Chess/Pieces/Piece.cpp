#include "Piece.hpp"

// Constructor
Piece::Piece(Color color, square position) : color(color), position(position) {}

// No setters for the following since these properties can't be changed
Color Piece::getColor() { return color; }
string Piece::getName() { return name; }
string Piece::getSymbol() { return (color == white ? "w" : "b") + symbol; }

int Piece::getRankIndex() { return position.first; }
int Piece::getFileIndex() { return position.second; }

bool Piece::isValidMove(square destination) {
    return true;
}
void Piece::move(square destination) {
    if(isValidMove(destination)) {
        position = destination;
    }
}
