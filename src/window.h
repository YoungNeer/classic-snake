#ifndef WINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "setup.h"
#define WINDOW_H

class Window{
private:
    sf::RenderWindow m_window;
    std::string m_windowTitle;
    sf::Vector2u m_windowSize;
    sf::Event m_event;
    bool m_isDone;
    bool m_isFullScreen;

    void create();
    void destroy();
    void winSetup(const std::string& l_winTitle,sf::Vector2u* l_winSize);

public:

    Window();
    Window(const std::string& l_winTitle,sf::Int16 l_winWidth,sf::Int16 l_winHeight);
    ~Window();
    sf::RenderWindow getWindow();
    void toggleFullScreen();
    bool isFullScreen();
    bool isOpen();

    void beginDraw();
    void endDraw();

    void setSize(sf::Int16 l_winWidth,sf::Int16 l_winHeight);
    void setSize(const sf::Vector2u&);

    sf::Vector2u getSize();

    void update();

    void draw(sf::Drawable& l_drawable);
    void close();
};

#endif // WINDOW_H
