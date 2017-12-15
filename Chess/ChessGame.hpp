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
    vector<vector<Piece*> > chessboard;

    Player* getActivePlayer(); // Player whose turn it is
    Player* getInactivePlayer();
    
    void setupChessboard();
    void displayChessboard();

    void changeTurn();
    
    Piece* getPieceFromStartingPosition(int rankIndex, int fileIndex);
    Piece* getPieceAtPosition(square position);
    void setPieceToPosition(Piece* piece, square destination);
    square squareFromNotation(string notation);
    bool processMove(string input);
    void promptInvalidInputMessage();
public:
    ChessGame();
    ~ChessGame();
    void startGame();
};

#endif
