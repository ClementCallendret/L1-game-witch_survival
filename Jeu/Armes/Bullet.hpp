#ifndef BULLET_HPP
#define BULLET_HPP
#include "../Animation.hpp"
#include "../Player.h"
#include "../ennemi.h"
#include <SFML/Graphics.hpp>


class Bullet
{
protected:
    sf::Vector2f location;
    float rayon, degats, speed;
    int life;

public:
    Bullet(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life);
    virtual ~Bullet() {};

    float getBulLife();
    virtual void hit(Ennemi* enemy);

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif