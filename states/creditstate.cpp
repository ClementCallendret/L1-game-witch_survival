#include <SFML/Graphics.hpp>
#include "creditstate.hpp"
#include "menustate.hpp"


void CCreditsState::Init()
{
    tex_lane.loadFromFile("media/wut.jpg");
    lane.setTexture(tex_lane); 

    music.openFromFile("media/Sounds/Main_Menu.ogg");
    music.play();
}

void CCreditsState::Cleanup()
{
    printf("CCreditsState Cleanup \n");
}

void CCreditsState::Pause()
{
    printf("CCreditsState Pause\n");
}

void CCreditsState::Resume()
{
    printf("CCreditsState Resume\n");
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
                game->Quit();
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
