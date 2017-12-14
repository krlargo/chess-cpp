#ifndef King_hpp
#define King_hpp

#include "Square.hpp"
#include <iostream>

class King: public Piece {
public:
  King(Square* sq);
  bool isValidMove(Square* sq);
};

#endif