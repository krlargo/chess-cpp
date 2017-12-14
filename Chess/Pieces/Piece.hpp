#ifndef Piece_hpp
#define Piece_hpp

#include "Square.hpp"
#include <iostream>

using namespace std;

class Square; //forward declaration

class Piece {
  string color, name;
  char symbol; //specifically the piece symbol only
  Square* square;
  int rank;
  char file;
  
public:
  
  string getColor();
  void setColor(string c);
  
  string getName();
  void setName(string n);
  
  char getFile();
  int getRank();
  
  Square* getSquare();
  void setSquare(Square* sq);
  
  char getSymbol();
  void setSymbol(char c);
  
  void move(Square* sq);
  
  virtual bool isValidMove(Square* sq) = 0;
};

#endif