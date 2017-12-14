#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

#include <iostream>

class Bishop: public Piece {
public:
    Bishop(Color color, square position);
};

#endif

