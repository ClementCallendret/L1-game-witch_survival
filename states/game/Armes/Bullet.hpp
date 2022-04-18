#ifndef BULLET_HPP
#define BULLET_HPP
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
    bool collision(Ennemi* enemy); // check les colisions entre un cercle et un rectangle
    virtual void hit(Ennemi* enemy);  // fait des dégats au projectile et a l'ennemi

    virtual void update() = 0;  // purement virtuel car ils ont tous un comportement different
    virtual void draw(sf::RenderWindow &window) = 0; // purment virtuel car ça dépend si on a un sprite ou une animation
};

#endif