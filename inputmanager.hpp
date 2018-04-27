#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManager
{
public:
    explicit InputManager();
    bool isKeyPressed(ALLEGRO_EVENT event, int key);
    bool isKeyPressed(ALLEGRO_EVENT event, std::vector<int> &keys);
    bool isKeyReleased(ALLEGRO_EVENT event, int key);
    bool isKeyReleased(ALLEGRO_EVENT event, std::vector<int> &keys);
private:
    ALLEGRO_KEYBOARD_STATE mKeyboardState;
};
