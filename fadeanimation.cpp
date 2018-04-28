#include "fadeanimation.hpp"

FadeAnimation::FadeAnimation()
{

}

void FadeAnimation::loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                                Position position)
{
    Animation::loadContent(image, text, position);
    mFadeSpeed = 1.0f;
    mIncrease = false;
}

void FadeAnimation::unloadContent()
{
    Animation::unloadContent();
    mFadeSpeed = 0.0f;
}

void FadeAnimation::update(InputManager event)
{
    if(mIsActive)
    {
        mAlpha += mIncrease ? mFadeSpeed : -mFadeSpeed;
        if(mAlpha <= 0)
        {
            mAlpha = 0;
            mIncrease = true;
        }
        else if(mAlpha >= 255)
        {
            mAlpha = 255;
            mIncrease = false;
        }
    }
    else
    {
        mAlpha = 255;
        mIncrease = false;
    }
}
