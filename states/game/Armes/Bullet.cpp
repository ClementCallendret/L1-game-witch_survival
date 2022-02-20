#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, float R, float D, float S, int Life) : location(pos), rayon(R), degats(D), speed(S), life(Life)
{
}


float Bullet::getBulLife()
{
    return life;
}

void Bullet::hit(Ennemi* enemy)
{
    life -= 1;
    enemy->PV -= degats;
}

