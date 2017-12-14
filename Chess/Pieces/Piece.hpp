#ifndef Piece_hpp
#define Piece_hpp

#include "Color.hpp"

#include <iostream>

using namespace std;

class Piece {
protected:
    string name; // "bK", "wQ", etc. Used for ASCII-interface representation
    string symbol; // "K", "Q", etc.
    Color color;
    int rankIndex;
    int fileIndex;
    
public:
    Piece(Color color, int rankIndex, int fileIndex);

    Color getColor();
    string getName();
    string getSymbol();
    
    int getFileIndex();
    void setFileIndex(int index);
    
    int getRankIndex();
    void setRankIndex(int index);
    
    //virtual bool isValidMove(Square* sq) = 0;
};

#endif
