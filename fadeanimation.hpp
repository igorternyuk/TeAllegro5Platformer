#pragma once

#include "animation.hpp"

class FadeAnimation : public Animation
{
public:
    explicit FadeAnimation();

protected:
    virtual void loadContent(ALLEGRO_BITMAP *image, const std::string &text,
                             Animation::Position position);
    virtual void unloadContent();
    virtual void update(InputManager event);
private:
    float mFadeSpeed;
    bool mIncrease;
};
