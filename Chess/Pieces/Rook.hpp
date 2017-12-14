#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

#include <iostream>

class Rook: public Piece {
public:
    Rook(Color color, square position);
};

#endif

