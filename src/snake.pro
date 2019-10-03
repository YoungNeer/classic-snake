
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
CONFIG += c++11

SOURCES += main.cpp \
    window.cpp \
    game.cpp \
    snake.cpp \
    world.cpp \
    hud.cpp \
    mainmenu.cpp

HEADERS += \
    window.h \
    game.h \
    snake.h \
    world.h \
    hud.h \
    setup.h \
    mainmenu.h
