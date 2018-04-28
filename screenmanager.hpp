#pragma once

#include "utils.hpp"
#include "allegro5initializer.hpp"
#include "gamescreen.hpp"
#include "titlescreen.hpp"
#include "splashscreen.hpp"
#include "fadeanimation.hpp"

class ScreenManager
{
public:
    ~ScreenManager() {}
    enum
    {
        SCREEN_WIDTH = 800,
        SCREEN_HEIGHT = 600
    };
    enum ScreenID
    {
        TITLE_SCREEN,
        SPLASH_SCREEN,
        NUM_SCREEN
    };
    static ScreenManager &getInstance();
    void initialize();
    void switchScreen(ScreenID id);
    void addScreen(GameScreen::Ptr screen);
    void loadContent();
    void unloadContent();
    void update(ALLEGRO_EVENT event);
    void render(ALLEGRO_DISPLAY *display);

private:
    ScreenManager();
    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;
    ScreenManager(ScreenManager&&) = delete;
    ScreenManager&operator=(ScreenManager&&) = delete;
    void transition();

private:
    Allegro5Initializer mInitializer;
    my_unique_ptr<ALLEGRO_BITMAP> mTransitionImage;
    GameScreen::Ptr mCurrentScreen, mNewScreen;
    FadeAnimation mFading;
    bool mStartTransition;
};
