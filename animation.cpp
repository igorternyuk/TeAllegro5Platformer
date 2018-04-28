#include "animation.hpp"

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                            Animation::Position position)
{
    mImage = image;
    mText = text;
    mPosition = position;
    mAlpha = 255;
    mFont = al_load_font("Resources/Fonts/BRLNSR.TTF", 30, 0);
    mSourceRect = mImage;
    mIsActive = false;
}

void Animation::unloadContent()
{
    al_destroy_bitmap(mImage);
    al_destroy_bitmap(mSourceRect);
    al_destroy_font(mFont);
    mPosition.x = mPosition.y = 0.0f;
    mAlpha = 0;
}

void Animation::update(InputManager event)
{

}

void Animation::render(ALLEGRO_DISPLAY *display)
{
    if(mSourceRect != NULL)
    {
        al_draw_tinted_bitmap(mSourceRect, al_map_rgba(0,0,0,mAlpha),
                              mPosition.x, mPosition.y, 0);
    }
    else if(mImage != NULL)
    {
        al_draw_tinted_bitmap(mImage, al_map_rgba(0,0,0,mAlpha),
                              mPosition.x, mPosition.y, 0);
    }
    if(!mText.empty())
    {
        al_draw_text(mFont, al_map_rgba(0,255,0,mAlpha), mPosition.x,
                     mPosition.y, 0, mText.c_str());
    }
}
