#pragma once
#include <allegro5/allegro5.h>

class GameScreen
{
public:
    explicit GameScreen();
    virtual ~GameScreen();
    virtual void loadContent();
    virtual void unloadContent();
    virtual void update();
    virtual void render(ALLEGRO_DISPLAY *display);
};
