#ifndef HUD_H
#define HUD_H
#include "setup.h"
#include "Window.h"
class HUD
{
private:
    sf::Font mFont;
    sf::Text mScoreText;
    sf::Text mLivesText;
    sf::RectangleShape mRect;

public:
    HUD();
    void setLives(sf::Int8 x);
    void setScore(sf::Int8 x);
    void render(Window &win);
};

#endif // HUD_H
