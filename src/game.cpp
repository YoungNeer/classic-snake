#include "game.h"

Game::Game():

    win("Welcome to Snake",800,517),
    menu(hud.mFont),
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
    if (state==PLAY_STATE){
        controlSnake();
        snake.update(hud);
        world.update(snake,hud);
        if (snake.hasLost())
            snake.reset();
    }
    else{
        if (menu.update(win)){
            state=PLAY_STATE;
            win.setSize(751,584);
        }
        sf::sleep(sf::seconds(0.06));
    }
}

void Game::controlSnake(){
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
    if (state==MAINMENU_STATE)
        menu.render(win);
    else{
        world.render(win);
        snake.render(win);
        hud.render(win);
    }
    win.endDraw();
}

Window& Game::getWindow(){
    return win;
}
