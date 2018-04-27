#pragma once
#include "screenmanager.hpp"

#include <memory>
#include <functional>

template<typename T>
using my_unique_ptr = std::unique_ptr<T, std::function<void(T*)>>;

class Game
{
public:
    explicit Game();
    ~Game();
    void run();
private:
    enum { FPS = 60 };
    my_unique_ptr<ALLEGRO_DISPLAY> mDisplay;
    my_unique_ptr<ALLEGRO_TIMER> mTimer;
    my_unique_ptr<ALLEGRO_EVENT_QUEUE> mEventQueue;
    ALLEGRO_KEYBOARD_STATE mKeyboardState;
};
