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
}

void CMenuState::Pause()
{
}

void CMenuState::Resume()
{
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
                    
	        case sf::Keyboard::Add:
                volume += 10.;
                if (volume > 100) {
                    volume = 100.;
                 }
                music.setVolume(volume);
                break;

            case sf::Keyboard::Subtract:
                volume -= 10.;
                if (volume < 0) {
                    volume = 0.;
                 }
                 music.setVolume(volume);
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
                    game->ChangeState(new CPlayState());
                    break;

                case 1:
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
