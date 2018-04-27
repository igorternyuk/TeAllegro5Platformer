#pragma once

#include "allegro5initializer.hpp"
#include "screenmanager.hpp"
#include "utils.hpp"


class Game
{
public:
    explicit Game();
    ~Game();
    void run();
private:
    enum { FPS = 60 };
    //Allegro5Initializer initializer;
    ScreenManager &mScreenManager;
    my_unique_ptr<ALLEGRO_DISPLAY> mDisplay;
    my_unique_ptr<ALLEGRO_TIMER> mTimer;
    my_unique_ptr<ALLEGRO_EVENT_QUEUE> mEventQueue;
    ALLEGRO_KEYBOARD_STATE mKeyboardState;
};
