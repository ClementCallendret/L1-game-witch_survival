#include "BulletOrbe.hpp"
#include <cmath>

BulletOrbe::BulletOrbe(sf::Vector2f pos, float D, float S, int Life, Animation a, float ang, Player *p) : 
Bullet(pos, D, S, Life, a), angle(ang), tireur(p)
{
    location.x = tireur->getPlayerPos().x + 100 * cos(angle);
    location.y = tireur->getPlayerPos().y + 100 * sin(angle);
    dureeDeVie.restart();
}

void BulletOrbe::update()
{
    angle += speed;
    location.x = tireur->getPlayerPos().x + 100 * cos(angle);
    location.y = tireur->getPlayerPos().y + 100 * sin(angle);

    if(dureeDeVie.getElapsedTime() >= sf::seconds(life)) life = 0;
    
    anim->update();
}

void BulletOrbe::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}