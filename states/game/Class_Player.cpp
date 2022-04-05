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

    sf::RectangleShape lifebar(sf::Vector2f(PV*75/pvMax, 5)); // barre de vie du perso
    lifebar.setFillColor(sf::Color::Red);
    lifebar.setOrigin(75/2, 2.5);
    lifebar.setPosition(location.x, location.y - 30);
    
    window.draw(totlife);
    window.draw(lifebar);
    window.draw(sprite);
}


void Player::inputs()  // deplacement de notre joueur (Haut/Bas/Gauche/Droite) ainsi que l'arret lors de l'atteinte des bords de la map
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (location.x >= 3571.)
            location.x = 3571.;
        else {
        location.x += speed;
        sprite.setScale(-1,1);
        sens = 1;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (location.x <= 45.)
            location.x = 45.;
        else {
        location.x -= speed;
        sprite.setScale(1,1);
        sens = -1;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (location.y <= 45.)
            location.y = 45.;
            else {
        location.y -= speed; 
            }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (location.y >= 3283.)
            location.y = 3283.;
        else {
        location.y += speed;
        }
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


