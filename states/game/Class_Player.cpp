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

    // sf::CircleShape shape(200, f);
    // shape.setFillColor(sf::Color::Blue);
    // window.draw(shape);
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

