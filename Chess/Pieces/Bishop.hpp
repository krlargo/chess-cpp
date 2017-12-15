#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

#include <iostream>

class Bishop: public virtual Piece {
public:
    Bishop(Color color, square position);
    virtual bool isValidMove(vector<vector<Piece*> > chessboard, square destination);
};

#endif

