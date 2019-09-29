#include "game.h"


Game::Game():
    win("Hello",751,584),
    world(),
    snake()
{
    startBuffer.loadFromFile("assets/audio/start.ogg");
    startSound.setBuffer(startBuffer);
    startSound.play();
    world.spawnApple();
}

Game::~Game(){}

void Game::handleInput(){}

void Game::update(){
    win.update();
    setSnakeDirection();
    snake.update(hud);
    world.update(snake,hud);
    if (snake.hasLost())
        snake.reset();
}

void Game::setSnakeDirection(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and
            snake.getDirection()!=Direction::Down)
        snake.setDirection(Direction::Up);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and
            snake.getDirection()!=Direction::Up)
        snake.setDirection(Direction::Down);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and
            snake.getDirection()!=Direction::Left)
        snake.setDirection(Direction::Right);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and
            snake.getDirection()!=Direction::Right and snake.getDirection()!=Direction::None)
        snake.setDirection(Direction::Left);
}

void Game::render(){
    win.beginDraw();
    world.render(win);
    snake.render(win);
    hud.render(win);
    win.endDraw();
}

Window& Game::getWindow(){
    return win;
}
