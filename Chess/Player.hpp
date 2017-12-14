#ifndef Player_hpp
#define Player_hpp

#include "Global.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"

#include <stdio.h>
#include <unordered_map>
#include <vector>

class Player {
    const Color color;
    // Maps piece symbol to pieces vector for optimal access
    unordered_map<string, vector<Piece*> > pieces;

public:
    Player(Color color);
    
    void addPiece(Piece* piece);
    vector<Piece*> getPiecesOfType(string symbol);
    vector<Piece*> getAllPieces();
};

#endif /* Player_hpp */
