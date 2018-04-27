#include "screenmanager.hpp"

ScreenManager::ScreenManager():
    mCurrentScreen{ std::make_unique<SplashScreen>() }
{}

ScreenManager& ScreenManager::getInstance()
{
    static ScreenManager screenManager;
    return screenManager;
}

void ScreenManager::initialize()
{}

void ScreenManager::addScreen(GameScreen::Ptr screen)
{
    mCurrentScreen->unloadContent();
    mCurrentScreen.reset(nullptr);
    mCurrentScreen.swap(screen);
}

void ScreenManager::loadContent()
{
    mCurrentScreen->loadContent();
}

void ScreenManager::unloadContent()
{
    mCurrentScreen->unloadContent();
}

void ScreenManager::update(ALLEGRO_EVENT event)
{
    mCurrentScreen->update(event);
}

void ScreenManager::render(ALLEGRO_DISPLAY *display)
{
    mCurrentScreen->render(display);
}
