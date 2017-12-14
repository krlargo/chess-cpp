#ifndef Queen_hpp
#define Queen_hpp

#include "Piece.hpp"

#include <iostream>

class Queen: public Piece {
public:
    Queen(Color color, int rankIndex, int fileIndex);
};

#endif

