#include "snake.h"
#ifndef WORLD_H
#define WORLD_H


class World
{
private:
    sf::Texture mBackgroundTexture;
    sf::RectangleShape mRect;
    sf::Sprite mBackground;
    struct{
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2i pos;        //position of the apple in the grid
    }mApple;
public:
    World();
    void spawnApple();
    void update(Snake& snake,HUD &hud);
    void render(Window& win);
};

#endif // WORLD_H
