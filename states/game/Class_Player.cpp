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
    
    sf::RectangleShape totXP(sf::Vector2f(1550, 15));
    totXP.setOrigin(775, 0);
    totXP.setPosition(location.x, location.y - 440);
    totXP.setFillColor(sf::Color(255, 255, 255, 127));
    totXP.setOutlineColor(sf::Color::Black);
    totXP.setOutlineThickness(2);

    sf::RectangleShape XPbar(sf::Vector2f(xp*1550/xpMax, 15));
    XPbar.setOrigin(775, 0);
    XPbar.setFillColor(sf::Color(20, 90, 180, 200));
    XPbar.setPosition(location.x, location.y - 440);
    // shape.setFillColor(sf::Color::Blue);
    // window.draw(shape);
    window.draw(totlife);
    window.draw(lifebar);
    window.draw(totXP);
    window.draw(XPbar);
    window.draw(sprite);
}


void Player::inputs()  // deplacement de notre joueur (Haut/Bas/Gauche/Droite)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        location.x += speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        location.x -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        location.y -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        location.y += speed;
    }
}

void Player::heal(float n)
{
    PV += n;
    if(PV > pvMax)
    {
        PV = pvMax;
    }
}

bool Player::prendreXP(float n){
    if(xp + n >= xpMax)
    {
        xp = n - (xpMax - xp);
        xpMax *= 1.1;
        return 1;
    }
    else xp += n;
    return 0;
}