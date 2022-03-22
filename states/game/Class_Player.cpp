#include "Player.h"

Player::Player()
{ 
    if (!texture.loadFromFile("media/witch_test.gif"))
        return;

    sprite.setTexture(texture);
    sprite.setOrigin(16,16);
}

void Player::draw(sf::RenderWindow &window)
{
    sprite.setPosition(location.x, location.y); // pour deplacer l'image de notre joueur il faut deja la placer 

    sf::RectangleShape totlife(sf::Vector2f(75, 5));
    totlife.setOutlineColor(sf::Color::Black);
    totlife.setOutlineThickness(1);
    totlife.setFillColor(sf::Color(255, 255, 255, 127));
    totlife.setOrigin(75/2, 2.5);
    totlife.setPosition(location.x, location.y - 30);

    sf::RectangleShape lifebar(sf::Vector2f(PV*75/pvMax, 5));
    lifebar.setFillColor(sf::Color::Red);
    lifebar.setOrigin(75/2, 2.5);
    lifebar.setPosition(location.x, location.y - 30);
    
    window.draw(totlife);
    window.draw(lifebar);
    window.draw(sprite);
}


void Player::inputs()  // deplacement de notre joueur (Haut/Bas/Gauche/Droite)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        location.x += speed;
        sprite.setScale(-1,1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        location.x -= speed;
        sprite.setScale(1,1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        location.y -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        location.y += speed;
    }
    newlevel = 0;
}

void Player::heal(float n)
{
    PV += n;
    if(PV > pvMax)
    {
        PV = pvMax;
    }
}

void Player::prendreXP(float n){
    if(xp + n >= xpMax)
    {
        xp = n - (xpMax - xp);
        xpMax *= 1.1;
        newlevel = 1;
    }
    else xp += n;
}
