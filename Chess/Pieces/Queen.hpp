#ifndef Queen_hpp
#define Queen_hpp

#include "Bishop.hpp"
#include "Rook.hpp"

#include <iostream>

class Queen: public Bishop, public Rook {
public:
    Queen(Color color, square position);
    virtual bool isValidMove(vector<vector<Piece*> > chessboard, square destination);
};

#endif

