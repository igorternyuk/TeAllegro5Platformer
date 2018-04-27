#pragma once

#include "gamescreen.hpp"
#include "splashscreen.hpp"
#include "allegro5initializer.hpp"

class ScreenManager
{
private:
    ScreenManager();
    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;
    ScreenManager(ScreenManager&&) = delete;
    ScreenManager&operator=(ScreenManager&&) = delete;
    Allegro5Initializer mAllegro5Initializer;
    GameScreen *mCurrentScreen, *mNewScreen;
public:
    enum
    {
        SCREEN_WIDTH = 800,
        SCREEN_HEIGHT = 600
    };
    ~ScreenManager() {}
    static ScreenManager &getInstance();
    void initialize();
    void loadContent();
    void update();
    void render(ALLEGRO_DISPLAY *display);
};
