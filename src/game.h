#ifndef GAME_H
#include "mainmenu.h"
#include "world.h"
#define GAME_H

class Game
{
private:
    Window win;
    sf::Sound startSound;
    sf::SoundBuffer startBuffer;
    float dt;
    MainMenu menu;
    World world;
    HUD hud;
    Snake snake;
    GameState state=MAINMENU_STATE;

    void controlSnake();
public:
    Game();
    ~Game();

    Window& getWindow();

    void handleInput();
    void update();
    void render();
};

#endif // GAME_H
