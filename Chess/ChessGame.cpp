#include "ChessGame.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"

#include <regex>

ChessGame::ChessGame() {
    // Assign default values
    turn = white;
    isCheck = isCheckmate = false;
    
    whitePlayer = new Player(white);
    blackPlayer = new Player(black);
    
    setupChessboard();
}

ChessGame::~ChessGame() {
    delete whitePlayer;
    delete blackPlayer;
    
    for(int rankIndex = 0; rankIndex < 8; rankIndex++)
        for(int fileIndex = 0; fileIndex < 8; fileIndex++) {
            Piece* piece = chessboard[rankIndex][fileIndex];
            if(piece) delete piece;
        }
}

void ChessGame::changeTurn() {
    turn = (turn == white ? black : white);
}

Player* ChessGame::getActivePlayer() {
    return turn == white ? whitePlayer : blackPlayer;
}

Player* ChessGame::getInactivePlayer() {
    return turn == white ? blackPlayer : whitePlayer;
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
        
        vector<Piece*> rankRow;

        for(int fileIndex = 0; fileIndex < 8; fileIndex++) {
            
            // Get piece based on starting position
            Piece* piece = getPieceFromStartingPosition(rankIndex, fileIndex);
            
            // Instantiate Square object (empty squares will be null)
            rankRow.push_back(piece);
            
            // If a piece exists at the position, add it to the appropriate player
            if(piece) {
                Player* player = rankIndex < 4 ? whitePlayer : blackPlayer;
                player->addPiece(piece);
            }
        }
        
        chessboard.push_back(rankRow);
    }
}

Piece* ChessGame::getPieceAtPosition(square position) {
    int rankIndex = position.first;
    int fileIndex = position.second;
    return chessboard[rankIndex][fileIndex];
}

void ChessGame::setPieceToPosition(Piece* movingPiece, square destination) {
    Piece* pieceAtNewPosition = getPieceAtPosition(destination);
    
    // "Eat" piece at destination square
    if(pieceAtNewPosition)
        getInactivePlayer()->losePiece(pieceAtNewPosition);
  
    // New position points to movingPiece
    chessboard[destination.first][destination.second] = movingPiece;
    
    // Nullify old position
    chessboard[movingPiece->getRankIndex()][movingPiece->getFileIndex()] = NULL;
    
    // Assign new location to movingPiece
    movingPiece->move(destination);
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
    cout << "    a   b   c   d   e   f   g   h" << endl << endl;
}

// Takes the destination notation and returns the index pair equivalent e.g. "e4"->(4,3)
square ChessGame::squareFromNotation(string notation) {
    int rankIndex = notation[1] - '1';
    int fileIndex = tolower(notation[0]) - 'a';
    return square(rankIndex, fileIndex);
}

// The move input is valid; check if actual move is valid
bool ChessGame::processMove(string input) {
    // Input length should be 3; if it's 2 then move is for Pawn (omitted P)
    char symbol = input.length() == 2 ? 'P' : toupper(input[0]);
    string squareNotation = input.substr(input.length()-2,2); // Get last 2 characters of input
    
    square destination = squareFromNotation(squareNotation);
    
    vector<Piece*> pieceTypeVector = getActivePlayer()->getPiecesOfType(symbol);
    vector<Piece*>::iterator it;
    
    for(it = pieceTypeVector.begin(); it != pieceTypeVector.end(); it++) {
        Piece* piece = *it;
        
        if(!piece) {
            getActivePlayer()->removePieceFromTypeAtPosition(symbol, it);
            continue;
        }
    
        // Check if piece can make the move
        if(piece->isValidMove(chessboard, destination)) {
            setPieceToPosition(piece, destination);
            return true; // TODO: Account for multiple pieces being capable of making the same move
        }
    }
    
    // We've iterated through all relevant pieces and none can legally make the move
    return false;
}

void ChessGame::promptInvalidInputMessage() {
    cout << "Invalid input. Enter a move using the following notation:" << endl;
    cout << "Enter a piece identifier:" << endl;
    cout << "- K: King" << endl;
    cout << "- Q: Queen" << endl;
    cout << "- B: Bishop" << endl;
    cout << "- N: Knight" << endl;
    cout << "- R: Rook" << endl;
    cout << "- P (or nothing): Pawn" << endl;
    cout << "and a square position to move to: (e.g. \"d4\" or \"e5\")"  << endl;
    cout << "to make a move (e.g. \"Kd4\" or \"Qe5\")" << endl << endl;
}

void promptIllegalMoveMessage() {
    cout << "Illegal move. Please enter a valid move." << endl << endl;
}

void ChessGame::startGame() {
    
    while(!isCheckmate) {
        displayChessboard();
        
        bool isValidInput = false, isValidMove = false;
        string moveInput;
        regex regexPattern("[PKQBNRpkqbnr]?[A-Ha-h][1-8]");
        
        do {
            moveInput = "";
            cout << (turn == white ? "White" : "Black") << "'s turn." << endl;
            cout << "Enter a move using chess notation: " << endl;
            cin >> moveInput;
            cout << endl;
            isValidInput = regex_match(moveInput, regexPattern);
            
            if(!isValidInput) {
                promptInvalidInputMessage();
            } else {
                isValidMove = processMove(moveInput);
                if(!isValidMove) {
                    promptIllegalMoveMessage();
                }
            }
        } while(!isValidInput || !isValidMove);
        
        changeTurn();
    }
}
