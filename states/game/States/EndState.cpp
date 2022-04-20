#include "EndState.hpp"
#include "MenuState.hpp"
#include <sstream>

void CEndState::Init()
{
    bg.setSize(sf::Vector2f(1600, 9000));
    bg.setOrigin(0, 0);
    bg.setFillColor(sf::Color(180, 130, 60));
    bg.setPosition(0, 0);

    txtfont.loadFromFile("media/Pixel.ttf");
    titlefont.loadFromFile("media/Witch.ttf");

    if (win)
    {
        music.openFromFile("media/Sounds/WIN.ogg");
        music.setVolume(53);
        title.setString("STAGE COMPLETED");
        title.setPosition(450, 100);
    }
    else
    {
        music.openFromFile("media/Sounds/Death.ogg");
        music.play();
        title.setString("DEFEAT");
        title.setPosition(600, 100);
    }
    title.setCharacterSize(100);
    title.setFont(titlefont);

    std::stringstream string1, string2;
    string1 << "Vous avez survecu " << int(time)/60 << "min " << int(time) % 60 << "sec";
    string2 << "Ennemis abbatus : " << kill;

    time_txt.setString(string1.str());
    time_txt.setPosition(300, 400);
    time_txt.setCharacterSize(50);
    time_txt.setFont(txtfont);
    time_txt.setOutlineThickness(2);
    time_txt.setOutlineColor(sf::Color::Black);

    kill_txt.setString(string2.str());
    kill_txt.setPosition(300, 500);
    kill_txt.setCharacterSize(50);
    kill_txt.setFont(txtfont);
    kill_txt.setOutlineThickness(2);
    kill_txt.setOutlineColor(sf::Color::Black);
    
    quitter_txt.setString("appuyer sur echap pour quitter");
    quitter_txt.setPosition(440, 700);
    quitter_txt.setCharacterSize(35);
    quitter_txt.setFont(txtfont);
    
}

void CEndState::Cleanup()
{
}

void CEndState::Pause()
{
}

void CEndState::Resume()
{
}

void CEndState::HandleEvents(CGameEngine *game)
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
                game->ChangeState(new CMenuState);
                break;
            default:
                break;
            }
        }
    }
}

void CEndState::Update(CGameEngine *game)
{
}

void CEndState::Draw(CGameEngine *game)
{
    game->screen->clear();
    game->screen->draw(bg);
    game->screen->draw(title);
    game->screen->draw(time_txt);
    game->screen->draw(kill_txt);
    game->screen->draw(quitter_txt);
    game->screen->display();
}
