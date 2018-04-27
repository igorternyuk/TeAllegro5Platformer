#include "game.hpp"
#include <stdexcept>

Game::Game():
    mDisplay{ al_create_display(ScreenManager::SCREEN_WIDTH,
                               ScreenManager::SCREEN_HEIGHT),
             al_destroy_display},
    mTimer{ al_create_timer(1.0f / FPS), al_destroy_timer},
    mEventQueue{ al_create_event_queue(), al_destroy_event_queue}
{
    /*mDisplay = al_create_display(ScreenManager::SCREEN_WIDTH,
                                ScreenManager::SCREEN_HEIGHT);*/

    if(mDisplay.get())
    {
        throw std::runtime_error("Could not create display");
    }


    //mEventQueue = al_create_event_queue();

    al_register_event_source(mEventQueue.get(), al_get_display_event_source(mDisplay.get()));
    al_register_event_source(mEventQueue.get(), al_get_keyboard_event_source());
    al_register_event_source(mEventQueue.get(), al_get_mouse_event_source());
    al_register_event_source(mEventQueue.get(), al_get_timer_event_source(mTimer.get()));
}

Game::~Game()
{
    //al_destroy_display(mDisplay);
    //al_destroy_timer(mTimer);
    //al_destroy_event_queue(mEventQueue);
}

void Game::run()
{


    bool isRunning = true;
    al_start_timer(mTimer.get());

    while(isRunning)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(mEventQueue.get(), &event);
        al_get_keyboard_state(&mKeyboardState);
    }
}
