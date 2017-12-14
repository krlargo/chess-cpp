#ifndef Piece_hpp
#define Piece_hpp

#include "Global.hpp"

#include <iostream>

using namespace std;

class Piece {
protected:
    string name; // "bK", "wQ", etc. Used for ASCII-interface representation
    string symbol; // "K", "Q", etc.
    Color color;
    square position;
    
public:
    Piece(Color color, square position);

    Color getColor();
    string getName();
    string getSymbol();
    
    int getRankIndex();
    int getFileIndex();
    
    //virtual bool isValidMove(square destination) = 0;
    bool isValidMove(square destination);
    void move(square destination);
};

#endif
