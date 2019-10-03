#include "mainmenu.h"
#include <iostream>
MainMenu::MainMenu(sf::Font& lFont)
{
    mBackTexture.loadFromFile("assets/images/splash.png");

    mBackground.setTexture(mBackTexture);


    mPlayText.setFont(lFont);
    mExitText.setFont(lFont);

    mPlayText.setString("Play the Game");
    mExitText.setString("Exit");

    mPlayText.setPosition(480,400);
    mExitText.setPosition(480,460);

    mPlayText.setColor(sf::Color::Yellow);
    mExitText.setColor(sf::Color::White);
}

bool MainMenu::update(Window &win){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        if (mSelected==1)
            return true;
        else
            win.close();

    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) or
             (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))){

        mSelected=(mSelected==1)?2:1;
        if (mSelected==1){
            mPlayText.setColor(sf::Color::Yellow);
            mExitText.setColor(sf::Color::White);
        }else{
            mPlayText.setColor(sf::Color::White);
            mExitText.setColor(sf::Color::Yellow);
        }
    }

    return false;
}

void MainMenu::render(Window &win){
    win.draw(mBackground);
    win.draw(mPlayText);
    win.draw(mExitText);
}
