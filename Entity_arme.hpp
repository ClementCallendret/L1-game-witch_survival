#ifndef ENTITY_ARME_HPP
#define ENTITY_ARME_HPP
#include <SFML/Graphics.hpp>
#include <string>


class Enemy : public sf::Transformable
{
public:
    float x, y, rayon, life;

    Enemy(float X, float Y, float R, float Life);

    void draw(sf::RenderWindow &window);
};

class Bullet : public sf::Transformable
{
public:
    float x, y, rayon, life, degats;
    Enemy *cible;

    Bullet(float X, float Y, float R, float D, Enemy & Cible);

    void update();

    bool collision(Enemy *a);

    void draw(sf::RenderWindow &window);
};

#endif