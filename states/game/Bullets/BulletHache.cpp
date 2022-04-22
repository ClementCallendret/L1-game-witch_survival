#include "BulletHache.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

BulletHache::BulletHache(sf::Vector2f pos, float D, float S, int Life, Animation a, Player* j, float rng, sf::Vector2f ciblePos) : 
Bullet(pos, D, S, Life, a), tireur(j), range(rng)
{
    float pente;
    float Cx = ciblePos.x;
    float Cy = ciblePos.y;
 
    if (location.x == Cx)
        pente = (location.y - Cy) / 0.01;
    else
        pente = (location.y - Cy) / (location.x - Cx);

    angle = atan(pente);
    if (location.x > Cx)
        angle += M_PI;
}

void BulletHache::update()
{

    if (distance < range)
    {
        location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne direction
        location.y += speed * sin(angle);

        distance += abs(speed * sin(angle)) + abs(speed * cos(angle));
    }
    else // lorsque la hache a atteint sa range max elle fait demi tour
    {
        location.x += speed * cos(angle+M_PI); // fait avvancer le projectiles dans la bonne direction
        location.y += speed * sin(angle+M_PI);

        distance += abs(speed * sin(angle+M_PI)) + abs(speed * cos(angle+M_PI));
        if(distance >= 2*range) life = 0;
    }

    anim->sprite.rotate(20); // on fait tournoyer la hache
    anim->update();
}

void BulletHache::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}