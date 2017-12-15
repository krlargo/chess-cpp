#include "Player.hpp"
#include "Global.hpp"

Player::Player(Color color) : color(color) {}

void Player::addPiece(Piece* piece) {
    char letter = piece->getLetter();
    pieces[letter].push_back(piece);
}

void Player::removePieceFromTypeAtPosition(char letter, vector<Piece*>::iterator it) {
    pieces[letter].erase(it);
}

void Player::losePiece(Piece* piece) {
    char letter = piece->getLetter();
    vector<Piece*>::iterator it = find(pieces[letter].begin(), pieces[letter].end(), piece);
    pieces[letter].erase(it); // Delete from vector
    delete piece; // Deallocate memory
}

vector<Piece*> Player::getPiecesOfType(char symbol) {
    return (pieces.find(symbol) == pieces.end() ? vector<Piece*>() : pieces[symbol]);
}
