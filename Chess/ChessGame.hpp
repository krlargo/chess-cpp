#ifndef ChessGame_hpp
#define ChessGame_hpp

#include "Square.hpp"

using namespace std;

enum Turn { white, black };

class ChessGame {
private:
    Turn turn;
    bool isCheck, isCheckmate, isValidInput;
    Square* board[8][8];

public:
    ChessGame();
    void setupChessboard();
    void displayChessboard();
    void startGame();
};

#endif
