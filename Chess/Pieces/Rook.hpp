#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

#include <iostream>

class Rook: public virtual Piece {
public:
    Rook(Color color, square position);
    virtual bool isValidMove(vector<vector<Piece*> > chessboard, square destination);
};

#endif

