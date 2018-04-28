#pragma once

#include "animation.hpp"

class FadeAnimation : public Animation
{
public:
    explicit FadeAnimation();

    virtual void loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                             Animation::Position position);
    virtual void unloadContent();
    virtual void update(InputManager event);
    virtual void setAlpha(int getAlpha) override;

private:
    void restrictAlpha();

private:
    float mFadeSpeed;
    bool mIncrease;

};
