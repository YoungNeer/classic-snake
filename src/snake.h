#include "hud.h"
#include "window.h"
#ifndef SNAKE_H
#define SNAKE_H
#include <deque>

struct SnakeSegment{
    SnakeSegment(int x,int y): position(x,y){}
    sf::Vector2i position;
};

typedef std::deque<SnakeSegment> SnakeContainer;

class Snake
{
private:
    sf::SoundBuffer mEatBuffer,mStartBuffer,mLoseBuffer;
    sf::Sound mEatSound,mStartSound,mLoseSound;
    sf::Texture mBodyTexture;
    sf::Sprite mBodySprite;
    SnakeContainer mBody;
    int mLives,mScore,mSpeed;
    bool mLost;
    Direction mDir;
    void checkCollision(HUD &hud);     //responsible for checking if snake hasn't bit itself

public:
    Snake();
    ~Snake();
    sf::Vector2i getPosition();
    void update(HUD &hud);
    void move();

    bool hasLost();
    int getLives();
    int getScore();
    void incrementScore(HUD &hud);
    void lose();
    void toggleLost();

    Direction getDirection();
    void setDirection(Direction l_dir);

    void growSnake();           //responsible for growing the snake size
    void reset();

    void cut(int l_segments, HUD &hud);   //responsible for cutting the snake
    void render(Window &l_win);
};

#endif // SNAKE_H
