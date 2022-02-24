#include "Bullet.hpp"
#include <stdio.h>
#include <cmath>

Bullet::Bullet(sf::Vector2f pos, float R, float D, float S, int Life) : 
location(pos), rayon(R), degats(D), speed(S), life(Life)
{
}

float Bullet::getBulLife()
{
    return life;
}

bool Bullet::collision(Ennemi *enemy)
{
    sf::Vector2f enemyPos = enemy->getEnnemiPos();
    sf::Vector2f enemyTaille = enemy->getEnnemiTaille();

    float distX = abs(location.x - enemyPos.x - enemyTaille.x / 2);
    float distY = abs(location.y - enemyPos.y - enemyTaille.y / 2);

    if (distX > (enemyTaille.x / 2 + rayon))
    {
        return false;
    }
    if (distY > (enemyTaille.y / 2 + rayon))
    {
        return false;
    }

    if (distX <= (enemyTaille.x / 2))
    {
        return true;
    }
    if (distY <= (enemyTaille.y / 2))
    {
        return true;
    }

    float dx = distX - enemyTaille.x / 2;
    float dy = distY - enemyTaille.y / 2;
    return ( (dx * dx + dy * dy ) <= (rayon * rayon));
}

void Bullet::hit(Ennemi *enemy)
{
    life -= 1;
    enemy->PV -= degats;
}
