#pragma once

#include "inputmanager.hpp"
#include <allegro5/allegro5.h>
#include <memory>

class GameScreen
{
public:
    using Ptr = std::unique_ptr<GameScreen>;
    explicit GameScreen();
    virtual ~GameScreen();
    virtual void loadContent();
    virtual void unloadContent();
    virtual void update(ALLEGRO_EVENT event);
    virtual void render(ALLEGRO_DISPLAY *display);
    InputManager getInputManager() const;

protected:
    InputManager mInput;
};
