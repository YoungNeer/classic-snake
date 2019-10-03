#include "hud.h"

HUD::HUD()
{

    mRect.setSize(sf::Vector2f(751,55));
    mRect.setFillColor(sf::Color(30,30,30,140));
    mRect.setPosition(sf::Vector2f(0,0));
    mFont.loadFromFile("assets/fonts/hacker.otf");
    mScoreText.setFont(mFont);
    mScoreText.setPosition(20,10);
    mScoreText.setColor(sf::Color(180,180,180));
    mLivesText.setColor(sf::Color(180,182,180));
    mScoreText.setString("Score: 0");
    mLivesText.setFont(mFont);
    mLivesText.setString("Lives: 3");
    mLivesText.setPosition(555,10);
}

void HUD::setLives(sf::Int8 x){
    mLivesText.setString("Lives: "+std::to_string(x));
}

void HUD::setScore(sf::Int8 x){
    mScoreText.setString("Score: "+std::to_string(x));
}

void HUD::render(Window &win){
//    win.draw(mRect);
    win.draw(mLivesText);
    win.draw(mScoreText);
}
