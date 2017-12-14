#ifndef Queen_hpp
#define Queen_hpp

#include "Square.hpp"
#include <iostream>

class Queen: public Piece {
  Square* walker;
public:
  Queen(Square* sq);
  bool isValidMove(Square* sq);
  bool isValidBishopMove(Square* sq);
  bool isValidRookMove(Square* sq);
};

#endif