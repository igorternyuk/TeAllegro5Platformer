#include "screenmanager.hpp"
#include <algorithm>

ScreenManager::ScreenManager():
    mTransitionImage{ al_load_bitmap("Resources/Images/bg.png"),
                      al_destroy_bitmap },
    mCurrentScreen{ std::make_unique<SplashScreen>() }
{}

void ScreenManager::transition()
{
    mFading.update(mCurrentScreen->getInputManager());
    if(mFading.getAlpha() >= 255)
    {
        mFading.setAlpha(255);
        mCurrentScreen->unloadContent();
        mCurrentScreen.swap(mNewScreen);
        mNewScreen.reset(nullptr);
        al_rest(0.5f);
    }
    else if(mFading.getAlpha() <= 0)
    {
        mStartTransition = false;
        mFading.setIsActive(false);
    }
}

ScreenManager& ScreenManager::getInstance()
{
    static ScreenManager screenManager;
    return screenManager;
}

void ScreenManager::initialize()
{}

void ScreenManager::addScreen(GameScreen::Ptr screen)
{
    mFading.setAlpha(0);
    mNewScreen.reset(nullptr);
    mNewScreen.swap(screen);
    mFading.setIsActive(true);
    mStartTransition = true;
}

void ScreenManager::loadContent()
{
    mCurrentScreen->loadContent();
    mFading.loadContent(mTransitionImage.get(), "", {0,0});
    mStartTransition = false;
}

void ScreenManager::unloadContent()
{
    mCurrentScreen->unloadContent();
    mFading.unloadContent();
}

void ScreenManager::update(ALLEGRO_EVENT event)
{
    if(mStartTransition)
        transition();
    else
        mCurrentScreen->update(event);
}

void ScreenManager::render(ALLEGRO_DISPLAY *display)
{
    mCurrentScreen->render(display);
    if(mStartTransition)
    {
        mFading.render(display);
        al_draw_text(mFading.getFont(), al_map_rgb(0,148,255), 5.f, 5.f, 0,
                     std::to_string(mFading.getAlpha()).c_str());
    }
}
