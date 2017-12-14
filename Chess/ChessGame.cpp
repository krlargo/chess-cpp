#include "ChessGame.hpp"
#include "King.hpp"


ChessGame::ChessGame() {
    turn = white;
    isCheck = isCheckmate = isValidInput = false;

    setupChessboard();
}

void ChessGame::setupChessboard() {
    // Insert Squares
    for(rank = 0; rank < 8; rank++)
        for(file = 0; file < 8; file++) {
            // Instantiate Square object
            board[rank][file] = new Square(rank + 1, file + 97);
            
            // Connect horizontally adjacent squares
            if()
            
            // Connect vertically adjacent squares
            
            // Get color
            
            // Assign piece
        }
    
    // Connect Squares
    // aboveSquares
    for(rank = 0; rank < 7; rank++)
        for(file = 0; file < 8; file++)
            board[rank][file]->setAboveSq(board[rank + 1][file]);
    
    // belowSquares
    for(rank = 1; rank < 8; rank++)
        for(file = 0; file < 8; file++)
            board[rank][file]->setBelowSq(board[rank - 1][file]);
    
    // leftSquares
    for(rank = 0; rank < 8; rank++)
        for(file = 1; file < 8; file++)
            board[rank][file]->setLeftSq(board[rank][file - 1]);
    
    // rightSquares
    for(rank = 0; rank < 8; rank++)
        for(file = 0; file < 7; file++)
            board[rank][file]->setRightSq(board[rank][file + 1]);
    
    
    
    /*//insert Kings
     for(rank = 0; rank < 8; rank += 7)
     board[rank][4]->piece = new King(board[rank][4]);
     
     //insert Queens
     for(rank = 0; rank < 8; rank += 7)
     board[rank][3]->piece = new Queen(board[rank][3]);
     
     //insert Bishops
     for(rank = 0; rank < 8; rank += 7)
     for(file = 2; file < 6; file += 3)
     board[rank][file]->piece = new Bishop(board[rank][file]);
     
     //insert Knights
     for(rank = 0; rank < 8; rank += 7)
     for(file = 1; file < 7; file += 5)
     board[rank][file]->piece = new Knight(board[rank][file]);
     
     //insert Rooks
     for(rank = 0; rank < 8; rank += 7)
     for(file = 0; file < 8; file += 7)
     board[rank][file]->piece = new Rook(board[rank][file]);
     
     //insert Pawns
     for(rank = 1; rank < 7; rank += 5)
     for(file = 0; file < 8; file++)
     board[rank][file]->piece = new Pawn(board[rank][file]);
     */
    
    
    //set colors
    for(rank = 0; rank < 2; rank++)
        for(file = 0; file < 8; file++)
            if(board[rank][file]->piece) //debug
                board[rank][file]->piece->setColor("white");
    
    for(rank = 6; rank < 8; rank++)
        for(file = 0; file < 8; file++)
            if(board[rank][file]->piece) //debug
                board[rank][file]->piece->setColor("black");
    
}

void ChessGame::displayChessboard()
{
    cout << "    a   b   c   d   e   f   g   h" << endl;
    for(rank = 7; rank >= 0; rank--)
    {
        cout << "  +---+---+---+---+---+---+---+---+" << endl << rank + 1 << " |";
        for(file = 0; file < 8; file++)
        {
            if(board[rank][file]->piece)
                cout << board[rank][file]->piece->getName() << " |";
            else
                cout << "   |";
            if(file == 7)
                cout << " " << rank + 1 << endl;
        }
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    a   b   c   d   e   f   g   h" << endl;
}

void ChessGame::play()
{
    displayChessboard();
    
}
