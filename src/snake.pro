
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
CONFIG += c++11

SOURCES += main.cpp \
    Window.cpp \
    game.cpp \
    snake.cpp \
    World.cpp \
    hud.cpp

HEADERS += \
    Window.h \
    game.h \
    snake.h \
    World.h \
    hud.h \
    setup.h
