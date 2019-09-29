#include "World.h"

World::World()
{
    mRect.setPosition(64,80);
    mRect.setFillColor(sf::Color::Transparent);
    mRect.setOutlineColor(sf::Color::Black);
    mRect.setOutlineThickness(2);
    mRect.setSize(sf::Vector2f(624,448));
    mBackgroundTexture.loadFromFile("assets/images/back2.png");
    mBackground.setTexture(mBackgroundTexture);

    sf::Vector2f tWorldSize(TILE_SIZE*GRID_WIDTH,TILE_SIZE*GRID_HEIGHT);
    mApple.texture.loadFromFile("assets/images/fruit.png");
    mApple.sprite.setTexture(mApple.texture);

}

void World::spawnApple(){
    mApple.pos=sf::Vector2i(rand()%(GRID_WIDTH-2)+1,rand()%(GRID_HEIGHT-2)+1);
    mApple.sprite.setPosition(64+mApple.pos.x*TILE_SIZE,80+mApple.pos.y*TILE_SIZE);
}

void World::update(Snake &snake,HUD &hud){
    if (snake.getPosition()==mApple.pos){
        snake.growSnake();
        snake.incrementScore(hud);
        spawnApple();
    }

    if ((snake.getPosition().x<=0 or snake.getPosition().x>=GRID_WIDTH-1) or
        (snake.getPosition().y<=0 or snake.getPosition().y>=GRID_HEIGHT-1)){
        snake.setDirection(Direction::None);
        snake.lose();
    }
}

void World::render(Window &win){
    win.draw(mBackground);
//    win.draw(mRect);
    win.draw(mApple.sprite);
}
