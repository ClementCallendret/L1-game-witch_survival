#include "gameengine.hpp"
#include "upgradestate.hpp"


void CUpgradeState::Init()
{
    tex_bg = new sf::Texture;
    (*tex_bg).loadFromFile("media/upgradeBG.png");

    bg = new sf::Sprite(*tex_bg);

    bg->setOrigin(sf::Vector2f(450, 450));
    bg->setPosition(playstate->view->getCenter());
	
    music.openFromFile("media/Sounds/Level_Up.ogg");
    music.play();
	
    ameliorations = new Upgrade(playstate->player, playstate->atirail, bg->getPosition());
}

void CUpgradeState::Cleanup()
{
    delete bg;
    delete tex_bg;
    delete ameliorations;
    playstate->clock.restart();
}

void CUpgradeState::Pause()
{
}

void CUpgradeState::Resume()
{
}

void CUpgradeState::HandleEvents(CGameEngine *game)
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
                game->PopState();
                break;

            case sf::Keyboard::Up:
                ameliorations->moveUp();
                break;

            case sf::Keyboard::Down:
                ameliorations->moveDown();
                break;
            
            case sf::Keyboard::Enter:
                ameliorations->choose();
                game->PopState();
                break;

            default :
                break;
            }
        }
    }
}

void CUpgradeState::Update(CGameEngine *game)
{
}

void CUpgradeState::Draw(CGameEngine *game)
{
    game->screen->clear();

    (game->screen)->draw(*playstate->map);
	playstate->player->draw(*(game->screen));
	playstate->wave->draw(*(game->screen));

    game->screen->draw(*bg);
    ameliorations->draw(*(game->screen));
    game->screen->display();
}
