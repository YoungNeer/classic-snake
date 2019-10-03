#ifndef MAINMENU_H
#include "window.h"
#define MAINMENU_H

class MainMenu
{
private:
    int mSelected=1;
    sf::Texture mBackTexture;
    sf::Sprite mBackground;
    sf::Text mPlayText,mExitText;
public:
    MainMenu(sf::Font&);
    bool update(Window &win);
    void render(Window &win);
};

#endif // MAINMENU_H
