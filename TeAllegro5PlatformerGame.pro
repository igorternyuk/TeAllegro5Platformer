TEMPLATE = app
CONFIG += c++1z
CONFIG -= app_bundle
CONFIG -= qt
LIBS += `pkg-config --libs allegro-5.0 allegro_dialog-5.0 allegro_ttf-5.0 allegro_font-5.0 allegro_primitives-5.0 allegro_image-5.0 allegro_audio-5.0 allegro_acodec-5.0`
SOURCES += main.cpp \
    screenmanager.cpp \
    gamescreen.cpp \
    splashscreen.cpp \
    game.cpp \
    allegro5initializer.cpp \
    inputmanager.cpp \
    titlescreen.cpp

HEADERS += \
    screenmanager.hpp \
    gamescreen.hpp \
    splashscreen.hpp \
    game.hpp \
    allegro5initializer.hpp \
    inputmanager.hpp \
    titlescreen.hpp \
    utils.hpp
