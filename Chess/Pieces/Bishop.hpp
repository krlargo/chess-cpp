#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

#include <iostream>

class Bishop: public Piece {
public:
    Bishop(Color color, int rankIndex, int fileIndex);
};

#endif

