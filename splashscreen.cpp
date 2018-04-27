#include "splashscreen.hpp"
#include "screenmanager.hpp"

SplashScreen::SplashScreen():
    mFont{ al_load_font("Resources/Fonts/BRLNSR.TTF", 40, 0),
           al_destroy_font }
{}

void SplashScreen::loadContent()
{
    //mFont = al_load_font("Resources/Fonts/BRLNSR.TTF", 40, 0);
}

void SplashScreen::unloadContent()
{
    //al_destroy_font(mFont);
}

void SplashScreen::update(ALLEGRO_EVENT event)
{
    if(mInput.isKeyReleased(event, ALLEGRO_KEY_ENTER))
    {
        GameScreen::Ptr ptr { std::make_unique<TitleScreen>() };
        ScreenManager::getInstance().addScreen(std::move(ptr));
    }
}

void SplashScreen::render(ALLEGRO_DISPLAY *display)
{
    al_draw_text(mFont.get(), al_map_rgb(255,0,0), 100, 100, 0, "Splash screen");
}
