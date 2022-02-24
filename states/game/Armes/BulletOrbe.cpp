#include "BulletOrbe.hpp"
#include <cmath>

BulletOrbe::BulletOrbe(sf::Vector2f pos, float R, float D, float S, int Life, float ang, Animation a, Player *p) : 
Bullet(pos, R, D, S, Life), angle(ang), anim(a), tireur(p)
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
    
    anim.update();
}

void BulletOrbe::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletOrbe::draw(sf::RenderWindow &window)
{
    /* sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(0, 255, 0, 127)); 
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    window.draw(hitbox); */

    anim.sprite.setPosition(location);
    window.draw(anim.sprite);
}