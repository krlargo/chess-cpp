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
    unordered_map<char, vector<Piece*> > pieces;

public:
    Player(Color color);
    // No need for destructor because board handles Piece deletion

    void addPiece(Piece* piece);
    void removePieceFromTypeAtPosition(char symbol, vector<Piece*>::iterator it);
    void losePiece(Piece* piece);
    vector<Piece*> getPiecesOfType(char symbol);
    vector<Piece*> getAllPieces();
};

#endif /* Player_hpp */
