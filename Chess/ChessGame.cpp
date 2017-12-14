#include "ChessGame.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"

ChessGame::ChessGame() {
    // Assign default values
    turn = white;
    isCheck = isCheckmate = false;

    setupChessboard();
}

Piece* ChessGame::getPieceFromStartingPosition(int rankIndex, int fileIndex) {
    // No pieces are initialized at these ranks
    if(rankIndex >= 2 && rankIndex <= 5) return NULL;
    
    square startPosition(rankIndex, fileIndex);
    
    // Return Pawns for ranks 2 & 7 (front rows)
    if(rankIndex == 1) return new Pawn(white, startPosition);
    if(rankIndex == 6) return new Pawn(black, startPosition);
    
    // Return other pieces at ranks 1 & 8, filtering by file
    if(rankIndex == 0 || rankIndex == 7) {
        
        Color color = rankIndex == 0 ? white : black;
        
        switch(fileIndex) {
            case 0: // File a
            case 7: // Files h
                return new Rook(color, startPosition);
                break;
            case 1: // File b
            case 6: // File g
                return new Knight(color, startPosition);
                break;
            case 2: // File c
            case 5: // File f
                return new Bishop(color, startPosition);
                break;
            case 3: // File d
                return new King(color, startPosition);
                break;
            case 4: // File e
                return new Queen(color, startPosition);
                break;
            default:
                return NULL;
        }
    }
    
    return NULL;
}

void ChessGame::setupChessboard() {
    for(int rankIndex = 0; rankIndex < 8; rankIndex++) {
        for(int fileIndex = 0; fileIndex < 8; fileIndex++) {
            
            // Get piece based on starting position
            Piece* piece = getPieceFromStartingPosition(rankIndex, fileIndex);
            
            // Instantiate Square object (empty squares will be null)
            chessboard[rankIndex][fileIndex] = piece;
        }
    }
}

Piece* ChessGame::getPieceAtPosition(square position) {
    int rankIndex = position.first;
    int fileIndex = position.second;
    return chessboard[rankIndex][fileIndex];
}

void ChessGame::setPieceToPosition(Piece* movingPiece, square destination) {
    // Check if piece can make a valid move to the destination square
    if(movingPiece->isValidMove(destination)) {
        Piece* pieceAtNewPosition = getPieceAtPosition(destination);
        
        // "Eat" piece at destination square
        if(pieceAtNewPosition) delete pieceAtNewPosition;
        
        // Move piece
        movingPiece->move(destination);
    }
}

void ChessGame::displayChessboard() {
    cout << "    a   b   c   d   e   f   g   h" << endl;
    for(int rankIndex = 7; rankIndex >= 0; rankIndex--)
    {
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << rankIndex + 1 << " |";
        for(int fileIndex = 0; fileIndex < 8; fileIndex++) {
            
            Piece* piece = chessboard[rankIndex][fileIndex];
            cout << (piece ? piece->getSymbol() + " |" : "   |"); // Print piece name
            
            // Print rank on the rhs of the board
            if(fileIndex == 7) cout << " " << rankIndex + 1 << endl;
        }
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    a   b   c   d   e   f   g   h" << endl;
}

void ChessGame::startGame() {
    displayChessboard();
    
    
}
