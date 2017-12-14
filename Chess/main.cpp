#include <iostream>
#include "ChessGame.hpp"

int main(int argc, const char * argv[]) {
    
    ChessGame* game = new ChessGame;
    game->startGame();
    
    return 0;
}
