#ifndef Square_hpp
#define Square_hpp

#include "Piece.hpp"
#include <iostream>

using namespace std;

// Forward declaration
class Piece;

class Square {
private:
    // Rank is assigned as char since we're more concerned with the symbol rather than the numerical value
    const char rank;
    const char file;
    
    Square *up, *down, *left, *right;
    Piece* piece;
    
public:
    Square(char r, char f);
        
    int getRank();
    char getFile();
    
    Piece* getPiece();
    void setPiece(Piece* p);
    
    Square* getAboveSq();
    Square* getBelowSq();
    Square* getLeftSq();
    Square* getRightSq();
    
    void setAboveSq(Square* sq);
    void setBelowSq(Square* sq);
    void setLeftSq(Square* sq);
    void setRightSq(Square* sq);
};

#endif
