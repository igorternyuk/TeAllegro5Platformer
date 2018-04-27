#include "titlescreen.hpp"
#include "screenmanager.hpp"

TitleScreen::TitleScreen():
    mFont{ al_load_font("Resources/Fonts/Sansation.ttf", 60, 0),
           al_destroy_font }
{

}

void TitleScreen::loadContent()
{
    //mFont = al_load_font("Resources/Fonts/Sansation.ttf", 60, 0);
}

void TitleScreen::unloadContent()
{
    //al_destroy_font(mFont);
}

void TitleScreen::update(ALLEGRO_EVENT event)
{
    if(mInputTitle.isKeyReleased(event, ALLEGRO_KEY_SPACE))
    {
        GameScreen::Ptr ptr { std::make_unique<SplashScreen>() };
        ScreenManager::getInstance().addScreen(std::move(ptr));
    }
}

void TitleScreen::render(ALLEGRO_DISPLAY *display)
{
    al_draw_text(mFont.get(), al_map_rgb(0,0,255), 100, 100, 0, "Title screen");
}
