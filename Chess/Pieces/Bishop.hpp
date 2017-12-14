#ifndef Bishop_hpp
#define Bishop_hpp

#include "Square.hpp"
#include <iostream>

class Bishop: public Piece {
public:
    Bishop(Square* sq);
    bool isValidMove(Square* sq);
};

#endif
