#include "Upgrade.hpp"

#include <algorithm>
#include <random>

Upgrade::Upgrade(Player *j, std::vector<Arme *> w, sf::Vector2f position) : joueur(j), weapons(w)
{
    std::shuffle(weapons.begin(), weapons.end(), std::random_device());
    std::sort(weapons.begin(), weapons.end(), [](Arme* lhs, Arme* rhs){ return lhs->m_levelMax < rhs->m_levelMax;});

    police.loadFromFile("media/Pixel.ttf");

    selecText.loadFromFile("media/upgradeSelec.png");
    selec.setTexture(selecText);
    selec.setPosition(sf::Vector2f(position.x - 400, position.y - 420));

    for (int i = 0; i < 3; i++)
    {
        options[i][0].setFont(police);
        options[i][0].setString(weapons[i]->m_description[0]);
        options[i][0].setFillColor(sf::Color::Black);
        options[i][0].setCharacterSize(40);

        options[i][1].setFont(police);
        options[i][1].setString(weapons[i]->m_description[1]);
        options[i][1].setFillColor(sf::Color::Black);
        options[i][1].setCharacterSize(30);
    }

    options[0][0].setPosition(sf::Vector2f(position.x - 210, position.y - 340));
    options[0][1].setPosition(sf::Vector2f(position.x - 340, position.y - 270));
    weapons[0]->m_icoSprite.setPosition(position.x - 320, position.y - 380);

    options[1][0].setPosition(sf::Vector2f(position.x - 210, position.y - 100));
    options[1][1].setPosition(sf::Vector2f(position.x - 340, position.y - 30));
    weapons[1]->m_icoSprite.setPosition(position.x - 320, position.y - 140);

    options[2][0].setPosition(sf::Vector2f(position.x - 210, position.y + 140));
    options[2][1].setPosition(sf::Vector2f(position.x - 340, position.y + 210));
    weapons[2]->m_icoSprite.setPosition(position.x - 320, position.y + 100);
}

void Upgrade::moveUp()
{
    options[choixSelected][0].setFillColor(sf::Color::Black);
    choixSelected--;
    if (choixSelected < 0)
    {
        choixSelected = 2;
        selec.move(sf::Vector2f(0, 480));
    }
    else
        selec.move(sf::Vector2f(0, -240));
}

void Upgrade::moveDown()
{
    options[choixSelected][0].setFillColor(sf::Color::Black);
    choixSelected++;
    if (choixSelected >= 3)
    {
        choixSelected = 0;
        selec.move(sf::Vector2f(0, -480));
    }
    else
        selec.move(sf::Vector2f(0, 240));
}

void Upgrade::choose(){
        weapons[choixSelected]->upgrade();

    }

void Upgrade::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 3; i++)
    {
        window.draw(options[i][0]);
        window.draw(options[i][1]);
        window.draw(weapons[i]->m_icoSprite);
    }
    window.draw(selec);
}