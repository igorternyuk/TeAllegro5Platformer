#pragma once

#include "inputmanager.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

class Animation
{
public:
    explicit Animation();
    virtual ~Animation();
    virtual void loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                             Position position);
    virtual void unloadContent();
    virtual void update(InputManager event);
    void render(ALLEGRO_DISPLAY *display);
protected:
    struct Position
    {
        float x, y;
        Position() { x = y = 0.0f; }
    };
    ALLEGRO_FONT *mFont;
    ALLEGRO_BITMAP *mImage, *mSourceRect;
    Position mPosition;
    float mAlpha;
    std::string mText;
    bool mIsActive = false;
};
