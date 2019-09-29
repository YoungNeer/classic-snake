#include "game.h"
int main(){
    Game game;

    while(game.getWindow().isOpen()){
        game.handleInput();
        sf::sleep(sf::seconds(0.1));
        game.update();
        game.render();
    }
}

