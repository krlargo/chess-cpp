#ifndef ChessGame_hpp
#define ChessGame_hpp

#include "Piece.hpp"
#include "Player.hpp"

using namespace std;

class ChessGame {
private:
    Color turn;
    bool isCheck, isCheckmate;
    Player *whitePlayer, *blackPlayer;
    Piece* chessboard[8][8];

    Player* getActivePlayer(); // Player whose turn it is

    void setupChessboard();
    void displayChessboard();

    Piece* getPieceFromStartingPosition(int rankIndex, int fileIndex);
    Piece* getPieceAtPosition(square position);
    void setPieceToPosition(Piece* piece, square destination);
    square squareFromNotation(string notation);
    bool processMove(string input);
    void promptInvalidInputMessage();
public:
    ChessGame();
    void startGame();
};

#endif
