#include <iostream>
#include "ChessGame.hpp"

int main(int argc, const char * argv[]) {
    ChessGame* game = new ChessGame;
    game->play();
    return 0;
}
