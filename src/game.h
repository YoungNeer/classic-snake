#include "World.h"
#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Window win;
    sf::Sound startSound;
    sf::SoundBuffer startBuffer;
    float dt;
    World world;
    HUD hud;
    Snake snake;

    void setSnakeDirection();
public:
    Game();
    ~Game();

    Window& getWindow();

    void handleInput();
    void update();
    void render();
};

#endif // GAME_H
