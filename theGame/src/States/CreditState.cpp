#include "CreditState.hpp"
#include "MenuState.hpp"


void CCreditsState::Init()
{
    tex_lane.loadFromFile("media/credits.jpeg");
    lane.setTexture(tex_lane); 

    music.openFromFile("media/Sounds/credits.ogg");
    music.play();
}

void CCreditsState::Cleanup()
{
}

void CCreditsState::Pause()
{
}

void CCreditsState::Resume()
{
}

void CCreditsState::HandleEvents(CGameEngine *game)
{
    sf::Event event;

    if (game->screen->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            game->Quit();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                music.stop();
                game->ChangeState(new CMenuState());
                break;
                    
            case sf::Keyboard::R:
                music.stop();
                game->ChangeState(new CMenuState());
                break;
         
            default :
                break;
            }
        }
    }
}   

void CCreditsState::Update(CGameEngine *game)
{
}

void CCreditsState::Draw(CGameEngine *game)
{
    game->screen->clear();
    game->screen->draw(lane);
    game->screen->display();
}