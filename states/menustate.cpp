#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameengine.hpp"
#include "menustate.hpp"
#include "playstate.hpp"

CMenuState CMenuState::m_MenuState;

void CMenuState::Init()
{
    tex_bg = new sf::Texture;
    (*tex_bg).loadFromFile("media/menu_bg.jpg");

    bg = new sf::Sprite(*tex_bg);
    menu = new MainMenu();
}

void CMenuState::Cleanup()
{
    delete bg;
    delete menu;
    delete tex_bg;

    printf("CMenuState Cleanup\n");
}

void CMenuState::Pause()
{
    printf("CMenuState Pause\n");
}

void CMenuState::Resume()
{
    printf("CMenuState Resume\n");
}

void CMenuState::HandleEvents(CGameEngine *game)
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

            case sf::Keyboard::Up:
                menu->moveUp();
                break;

            case sf::Keyboard::Down:
                menu->moveDown();
                break;

            case sf::Keyboard::Return:

                switch (menu->ChoixPresse())
                {
                case 0:
                    std::cout << "play pressed" << std::endl;
                    game->ChangeState(CPlayState::Instance());
                    break;

                case 1:
                    std::cout << "credit pressed" << std::endl;
                    break;

                case 2:

                    game->Quit();
                    break;

                default:
                    break;
                }

                break;
                
            default :
                break;
            }
        }
    }
}

void CMenuState::Update(CGameEngine *game)
{
}

void CMenuState::Draw(CGameEngine *game)
{
    game->screen->clear();
    game->screen->draw(*bg);
    menu->draw(*(game->screen));
    game->screen->display();
}