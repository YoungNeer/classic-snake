#ifndef HUD_H
#define HUD_H
#include "window.h"
class HUD
{
private:

    sf::Text mScoreText;
    sf::Text mLivesText;
    sf::RectangleShape mRect;

public:
    sf::Font mFont;
    HUD();
    void setLives(sf::Int8 x);
    void setScore(sf::Int8 x);
    void render(Window &win);
};

#endif // HUD_H
