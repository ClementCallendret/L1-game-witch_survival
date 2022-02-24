#include "BulletEclair.hpp"
#include <iostream>
#include <cmath>

BulletEclair::BulletEclair(sf::Vector2f pos, float R, float D, float S, int Life, Ennemi *C, Animation a) : 
Bullet(pos, R, D, S, Life), cible(C), anim(a)
{
    location = cible->getEnnemiPos();
}

void BulletEclair::update()
{
    //location = cible->getEnnemiPos();
    anim.update();
}

void BulletEclair::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletEclair::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    // window.draw(hitbox);

    // on dessine l'animation du projectile
    anim.sprite.setPosition(location);
    window.draw(anim.sprite);
    if (anim.num_frame > anim.nbtot_frames - 1) life = 0;
}