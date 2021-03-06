#include "game.hpp"
#include "inputmanager.hpp"
#include <stdexcept>
#include <iostream>

Game::Game():
    mScreenManager{ ScreenManager::getInstance() },
    mDisplay{ al_create_display(ScreenManager::SCREEN_WIDTH,
                               ScreenManager::SCREEN_HEIGHT),
             al_destroy_display},
    mTimer{ al_create_timer(1.0f / FPS), al_destroy_timer },
    mEventQueue{ al_create_event_queue(), al_destroy_event_queue }
{
    if(!mDisplay.get())
    {
        throw std::runtime_error("Could not create display");
    }

    al_set_window_position(mDisplay.get(), 100, 100);

    al_register_event_source(mEventQueue.get(), al_get_keyboard_event_source());
    al_register_event_source(mEventQueue.get(), al_get_mouse_event_source());
    al_register_event_source(mEventQueue.get(), al_get_display_event_source(mDisplay.get()));
    al_register_event_source(mEventQueue.get(), al_get_timer_event_source(mTimer.get()));
}

Game::~Game()
{}

void Game::run()
{
    bool isRunning = true;
    mScreenManager.initialize();
    mScreenManager.loadContent();
    InputManager inputManager;
    al_start_timer(mTimer.get());

    while(isRunning)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(mEventQueue.get(), &events);
        al_get_keyboard_state(&mKeyboardState);
        if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            isRunning = false;
        }
        else if(inputManager.isKeyReleased(events, ALLEGRO_KEY_ESCAPE))
        {
            isRunning = false;
        }

        mScreenManager.update(events);
        mScreenManager.render(mDisplay.get());

        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    mScreenManager.unloadContent();
}
