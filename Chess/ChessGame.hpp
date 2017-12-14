#ifndef ChessGame_hpp
#define ChessGame_hpp

#include "Piece.hpp";

using namespace std;

class ChessGame {
private:
    Color turn;
    bool isCheck, isCheckmate;
    
    Piece* chessboard[8][8];

    Piece* getPieceStartingAtPosition(int rankIndex, int fileIndex);

public:
    ChessGame();
    void setupChessboard();
    void displayChessboard();
    void startGame();
};

#endif
