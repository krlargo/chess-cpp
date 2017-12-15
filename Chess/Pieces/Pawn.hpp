#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

#include <iostream>

class Pawn: public Piece {
public:
    Pawn(Color color, square position);
    virtual ~Pawn() = default;
    virtual bool isValidMove(vector<vector<Piece*> > chessboard, square destination);
};

#endif
