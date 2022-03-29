#include "BulletEpee.hpp"

BulletEpee::BulletEpee(sf::Vector2f pos, float R, float D, float S, int Life, Animation a, Player* j, int s, float dist) :
Bullet(pos, R, D, S, Life), anim(a), tireur(j), sens(s), distance(dist)
{
    anim.sprite.scale(-sens, 1);
}

void BulletEpee::update()
{
    location = sf::Vector2f(tireur->getPlayerPos().x + sens*distance*anim.num_frame, tireur->getPlayerPos().y - 0.13*rayon*anim.num_frame);
    anim.update();
}

void BulletEpee::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletEpee::draw(sf::RenderWindow &window)
{
    /* sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127));
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    window.draw(hitbox); */

    anim.sprite.setPosition(tireur->getPlayerPos());
    window.draw(anim.sprite);
    if(anim.num_frame > anim.nbtot_frames - 1) { life = 0; anim.num_frame = 0;}
}