#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameengine.hpp"
#include "menustate.hpp"
#include "playstate.hpp"


void CMenuState::Init()
{
    tex_bg.loadFromFile("media/menu_bg.jpg");
    bg.setTexture(tex_bg);

    menu = new MainMenu();
    music.openFromFile("media/Sounds/Main_Menu.ogg");
    music.play();
}

void CMenuState::Cleanup()
{
    delete menu;

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
                    
            case sf::Keyboard::M:
                music.pause();
                break;

            case sf::Keyboard::P:
				music.play();
				break;

            case sf::Keyboard::Up:
                menu->moveUp();
                break;

            case sf::Keyboard::Down:
                menu->moveDown();
                break;

            case sf::Keyboard::Return:

                switch (menu->choixPresse())
                {
                case 0:
                    std::cout << "play pressed" << std::endl;
                    game->ChangeState(new CPlayState());
                    break;

                case 1:
                    std::cout << "credit pressed" << std::endl;
		    music.stop();
                    game->PushState(new CCreditsState());	
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
    game->screen->draw(bg);
    menu->draw(*(game->screen));
    game->screen->display();
}
