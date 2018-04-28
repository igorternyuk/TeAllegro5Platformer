#include "animation.hpp"

Animation::Animation():
    mFont{al_load_font("Resources/Fonts/BRLNSR.TTF", 30, 0),
          al_destroy_font}
{}

Animation::~Animation()
{}

void Animation::loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                            Animation::Position position)
{
    mImage = image;
    mText = text;
    mPosition = position;
    mAlpha = 255;
    mSourceRect = mImage;
    mIsActive = false;
}

void Animation::unloadContent()
{
    mPosition.x = mPosition.y = 0.0f;
    mAlpha = 0;
}

void Animation::update(InputManager event)
{}

void Animation::render(ALLEGRO_DISPLAY *display)
{
    auto sourceWidth = al_get_bitmap_width(mSourceRect);
    auto sourceHeight = al_get_bitmap_height(mSourceRect);
    auto destWidth = al_get_display_width(display);
    auto destHeight = al_get_display_height(display);
    if(mSourceRect != nullptr)
    {
        al_draw_tinted_scaled_bitmap(mSourceRect, al_map_rgba(0,0,0,mAlpha),
                                     mPosition.x, mPosition.y, sourceWidth,
                                     sourceHeight,0,0,destWidth, destHeight, 0);
    }

    if(!mText.empty())
    {
        al_draw_text(mFont.get(), al_map_rgba(0,255,0,mAlpha), mPosition.x,
                     mPosition.y, 0, mText.c_str());
    }
}

int Animation::getAlpha() const
{
    return mAlpha;
}

void Animation::setAlpha(int alpha)
{
    mAlpha = alpha;
}

bool Animation::isActive() const
{
    return mIsActive;
}

void Animation::setIsActive(bool isActive)
{
    mIsActive = isActive;
}

ALLEGRO_FONT *Animation::getFont() const
{
    return mFont.get();
}
