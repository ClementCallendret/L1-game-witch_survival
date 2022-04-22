#include "BulletEpee.hpp"

BulletEpee::BulletEpee(sf::Vector2f pos, float D, float S, int Life, Animation a, Player* j, int s) :
Bullet(pos, D, S, Life, a), tireur(j), sens(s)
{
    anim->sprite.scale(-sens, 1);
}

void BulletEpee::update()
{
    anim->update();
    location = tireur->getPlayerPos();
    life--;
}

void BulletEpee::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}