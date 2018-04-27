#include "screenmanager.hpp"

ScreenManager::ScreenManager()
{

}

ScreenManager& ScreenManager::getInstance()
{
    static ScreenManager screenManager;
    return screenManager;
}

void ScreenManager::initialize()
{
    mCurrentScreen = new SplashScreen();
}

void ScreenManager::loadContent()
{
    mCurrentScreen->loadContent();
}

void ScreenManager::update()
{
    mCurrentScreen->update();
}

void ScreenManager::render(ALLEGRO_DISPLAY *display)
{
    mCurrentScreen->render(display);
}
