#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameengine.hpp"
#include "pausestate.hpp"
#include "menustate.hpp"

void CPauseState::Init()
{
    tex_bg.loadFromFile("media/upgradeBG.png");

    bg.setTexture(tex_bg);
    bg.setOrigin(sf::Vector2f(450, 450));
    bg.setScale(0.75, 0.75);
    bg.setPosition(playstate->view->getCenter());
    music.openFromFile("media/Sounds/pause.ogg");
    music.setVolume(50.);
    music.play();

    titlefont.loadFromFile("media/Witch.ttf");
    choixfont.loadFromFile("media/Pixel.ttf");

    sf::Vector2f position = playstate->view->getCenter();

    title.setFont(titlefont);
    title.setString("Pause");
    title.setFillColor(sf::Color::Black);
    title.setCharacterSize(120);
    title.setPosition(sf::Vector2f(position.x - 120, position.y - 240));

    options[0].setFont(choixfont);
    options[0].setString("Reprendre");
    options[0].setFillColor(sf::Color::Black);
    options[0].setCharacterSize(50);
    options[0].setPosition(sf::Vector2f(position.x - 170, position.y + 10));
    options[0].setOutlineColor(sf::Color::White);

    options[1].setFont(choixfont);
    options[1].setString("Quitter");
    options[1].setFillColor(sf::Color::Black);
    options[1].setCharacterSize(50);
    options[1].setPosition(sf::Vector2f(position.x - 98, position.y + 120));
    options[1].setOutlineColor(sf::Color::White);
}

void CPauseState::Cleanup()
{
    playstate->clock.restart();

    printf("CMenuState Cleanup\n");
}

void CPauseState::Pause()
{
    printf("CMenuState Pause\n");
}

void CPauseState::Resume()
{
    printf("CMenuState Resume\n");
}

void CPauseState::HandleEvents(CGameEngine *game)
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
                if (choixSelected == 1)
                    choixSelected = 0;
                else
                    choixSelected = 1;
                break;

            case sf::Keyboard::Down:
                if (choixSelected == 1)
                    choixSelected = 0;
                else
                    choixSelected = 1;
                break;

            case sf::Keyboard::Enter:
                if (choixSelected == 0)
                    game->PopState();
                else
                {
                    playstate->view->setCenter(800, 450);
                    game->screen->setView(*playstate->view);
                    game->ChangeState(new CMenuState());
                }
                break;

            default:
                break;
            }
        }
    }
}

void CPauseState::Update(CGameEngine *game)
{
    for (int i = 0; i < 2; i++)
    {
        if (i == choixSelected)
            options[i].setOutlineThickness(2);
        else
            options[i].setOutlineThickness(0);
    }
}

void CPauseState::Draw(CGameEngine *game)
{
    game->screen->clear();

    (game->screen)->draw(*playstate->map);
    playstate->player->draw(*(game->screen));
    playstate->wave->draw(*(game->screen));

    game->screen->draw(bg);
    game->screen->draw(title);
    game->screen->draw(options[0]);
    game->screen->draw(options[1]);
    game->screen->display();
}
