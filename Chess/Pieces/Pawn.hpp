#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

#include <iostream>

class Pawn: public Piece {
public:
    Pawn(Color color, int rankIndex, int fileIndex);
};

#endif
