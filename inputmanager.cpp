#include "inputmanager.hpp"

InputManager::InputManager()
{}

bool InputManager::isKeyPressed(ALLEGRO_EVENT event, int key)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        return event.keyboard.keycode == key;
    }
    return false;
}

bool InputManager::isKeyPressed(ALLEGRO_EVENT event, std::vector<int> &keys)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        for(auto key: keys)
            if(event.keyboard.keycode == key)
                return true;

    }
    return false;
}

bool InputManager::isKeyReleased(ALLEGRO_EVENT event, int key)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        return event.keyboard.keycode == key;
    }
    return false;
}

bool InputManager::isKeyReleased(ALLEGRO_EVENT event, std::vector<int> &keys)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        for(auto key: keys)
            if(event.keyboard.keycode == key)
                return true;

    }
    return false;
}
