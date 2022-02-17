#include "Bullet.hpp"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

Bullet::Bullet(sf::Vector2f pos, float R, float D, float S, int Life, Animation* a) : location(pos), rayon(R), degats(D), speed(S), life(Life), bul_anim(*a)
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


void Bullet::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    window.draw(hitbox);

    // on dessine l'animation du projectile
    bul_anim.sprite.setPosition(location);
    window.draw(bul_anim.sprite);
}
