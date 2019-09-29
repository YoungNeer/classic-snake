#include "Window.h"

Window::Window(){
    winSetup("hello world",new sf::Vector2u(640,480));
}

Window::Window(const std::string& l_winTitle,sf::Int16 l_winWidth,sf::Int16 l_winHeight){
    winSetup(l_winTitle,new sf::Vector2u(l_winWidth,l_winHeight));
}

Window::~Window(){
    destroy();
}

void Window::create(){
    m_window.create(sf::VideoMode(m_windowSize.x,m_windowSize.y),m_windowTitle,
                    m_isFullScreen ? sf::Style::Fullscreen : sf::Style::None);
    m_window.setPosition(sf::Vector2i(350,100));
}

void Window::winSetup(const std::string& l_winTitle,sf::Vector2u* l_winSize){
    m_windowSize=*l_winSize;
    m_windowTitle=l_winTitle;
    m_isDone=m_isFullScreen=false;
    create();
}

void Window::destroy(){
    m_window.close();
}

void Window::update(){
    while(m_window.pollEvent(m_event)){
        if (m_event.type==sf::Event::Closed or
                (m_event.type==sf::Event::KeyPressed and
                m_event.key.code==sf::Keyboard::Escape))
            m_isDone=true;
        else if (m_event.type==sf::Event::KeyPressed and
                 m_event.key.code==sf::Keyboard::F5)
            toggleFullScreen();
    }
}

void Window::toggleFullScreen(){
    destroy();
    m_isFullScreen=not m_isFullScreen;
    create();
}

void Window::beginDraw(){
    m_window.clear(sf::Color::Black);
}

void Window::draw(sf::Drawable& l_drawable){
    m_window.draw(l_drawable);
}

void Window::endDraw(){
    m_window.display();
}

sf::Vector2u Window::getSize(){
    return m_windowSize;
}

void Window::setSize(sf::Int16 l_winWidth, sf::Int16 l_winHeight){
    setSize(sf::Vector2u(l_winWidth, l_winHeight));
}

void Window::setSize(const sf::Vector2u& l_Size){
    m_windowSize=l_Size;
    destroy();
    create();
}

bool Window::isFullScreen(){
    return m_isFullScreen;
}

bool Window::isOpen(){
    return not m_isDone;
}


