#pragma once

#include "utils.hpp"
#include "gamescreen.hpp"
#include "inputmanager.hpp"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class TitleScreen: public GameScreen
{
public:
    explicit TitleScreen();
    virtual ~TitleScreen() {}
    virtual void loadContent();
    virtual void unloadContent();
    virtual void update(ALLEGRO_EVENT event);
    virtual void render(ALLEGRO_DISPLAY *display);

private:
    my_unique_ptr<ALLEGRO_FONT> mFont;
};
