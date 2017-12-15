#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

#include <iostream>

class King: public Piece {
public:
    King(Color color, square position);
    virtual bool isValidMove(vector<vector<Piece*> > chessboard, square destination);
};

#endif

