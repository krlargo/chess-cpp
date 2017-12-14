#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

#include <iostream>

class King: public Piece {
public:
    King(Color color, int rankIndex, int fileIndex);
};

#endif

