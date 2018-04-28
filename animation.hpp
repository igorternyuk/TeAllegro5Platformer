#pragma once

#include "utils.hpp"
#include "inputmanager.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

class Animation
{
public:
    struct Position
    {
        float x, y;
    };
    explicit Animation();
    virtual ~Animation();
    virtual void loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                             Position position);
    virtual void unloadContent();
    virtual void update(InputManager event);
    void render(ALLEGRO_DISPLAY *display);

    int getAlpha() const;
    virtual void setAlpha(int getAlpha);
    bool isActive() const;
    void setIsActive(bool isActive);
    ALLEGRO_FONT* getFont() const;

protected:
    my_unique_ptr<ALLEGRO_FONT> mFont;
    ALLEGRO_BITMAP *mImage, *mSourceRect;
    Position mPosition;
    int mAlpha;
    std::string mText;
    bool mIsActive = false;
};
