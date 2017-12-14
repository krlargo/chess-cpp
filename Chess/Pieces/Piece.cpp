#include "Piece.hpp"

// Constructor
Piece::Piece(Color color, int rankIndex, int fileIndex) : color(color), fileIndex(fileIndex), rankIndex(rankIndex) {}

// No setters for the following since these properties can't be changed
Color Piece::getColor() { return color; }
string Piece::getName() { return name; }
string Piece::getSymbol() { return (color == white ? "w" : "b") + symbol; }

int Piece::getFileIndex() { return fileIndex; }
void Piece::setFileIndex(int index) { this->fileIndex = index; }

int Piece::getRankIndex() { return rankIndex; }
void Piece::setRankIndex(int index) { this->rankIndex = index; }

/*
void Piece::move(Square* targetSquare)
{
  //add more for King moving into check
  if(targetSquare->piece && targetSquare->piece->getColor() != color) //if enemy piece exists in target square
  {
    targetSquare->piece->setSquare(NULL); //piece no longer points to square
    targetSquare->piece = NULL; //square no longer points to piece
  }
  
  square->piece = NULL; //square's old piece no longer points to it
  this->setSquare(targetSquare); //new piece points to targetSquare
  targetSquare->piece = this; //targetSquare points to new piece
}
*/
