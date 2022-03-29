#include "BulletEclair.hpp"

BulletEclair::BulletEclair(sf::Vector2f pos, float R, float D, float S, int Life, Ennemi *C, Animation a) : 
Bullet(pos, R, D, S, Life), cible(C), anim(a)
{
    location = cible->getEnnemiPos();
}

void BulletEclair::update()
{
    anim.update();
}

void BulletEclair::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletEclair::draw(sf::RenderWindow &window)
{
    /* sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127));
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    window.draw(hitbox); */

    anim.sprite.setPosition(location); 
    window.draw(anim.sprite);
    if (anim.num_frame > anim.nbtot_frames - 1) life = 0;
}