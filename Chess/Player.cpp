#include "Player.hpp"
#include "Global.hpp"

Player::Player(Color color) : color(color) {}

void Player::addPiece(Piece* piece) {
    string letter = string(1,piece->getLetter());
    pieces[letter].push_back(piece);
}

vector<Piece*> Player::getPiecesOfType(string symbol) {
    return (pieces.find(symbol) == pieces.end() ? vector<Piece*>() : pieces[symbol]);
}
