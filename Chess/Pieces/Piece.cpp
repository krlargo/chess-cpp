#include "Piece.hpp"

string Piece::getColor()
{ return color; }

void Piece::setColor(string c)
{
  color = c;
  name = c[0] + name;
}

string Piece::getName()
{ return name; }

void Piece::setName(string n)
{
  name = n;
  symbol = n[0];
}

char Piece::getFile()
{ return file; }


int Piece::getRank()
{ return rank; }

Square* Piece::getSquare()
{ return square; }

void Piece::setSquare(Square* sq)
{ square = sq; }

char Piece::getSymbol()
{ return symbol; }

void Piece::setSymbol(char c)
{ symbol = c; }

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