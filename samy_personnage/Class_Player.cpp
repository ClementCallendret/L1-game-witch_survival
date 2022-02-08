#include <SFML/Graphics.hpp>

#include "Player.h"

Player::Player()
{
}

void Player::draw(sf::RenderWindow &window)
{
    sf::Texture texture;
    if (!texture.loadFromFile("media/fun_image.jpg"))
        return;

    sf::Sprite sprite(texture);

    sprite.setPosition(location.x, location.y); // deplacer l'image

    // sf::CircleShape shape(200, f);
    // shape.setFillColor(sf::Color::Blue);
    // window.draw(shape);
    window.draw(sprite);
}

void Player::inputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        location.x += speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        location.x -= speed;
    }
}
