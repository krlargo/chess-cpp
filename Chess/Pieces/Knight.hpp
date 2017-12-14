#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

#include <iostream>

class Knight: public Piece {
public:
    Knight(Color color, int rankIndex, int fileIndex);
};

#endif

