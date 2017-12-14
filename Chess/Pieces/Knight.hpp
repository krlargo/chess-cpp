#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

#include <iostream>

class Knight: public Piece {
public:
    Knight(Color color, square position);
    virtual bool isValidMove(square destination);
};

#endif

