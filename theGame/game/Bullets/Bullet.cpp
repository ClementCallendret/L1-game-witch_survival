#include "Bullet.hpp"
#include "../Collision.hpp"
#include <stdio.h>

Bullet::Bullet(sf::Vector2f pos, float D, float S, int Life, Animation a) : 
location(pos), degats(D), speed(S), life(Life)
{
    anim = new Animation {a};
}

float Bullet::getBulLife()
{
    return life;
}

bool Bullet::collision(Ennemi *enemy)
{
    return Collision::PixelPerfectTest(anim->sprite, enemy->anim.sprite);
}

void Bullet::hit(Ennemi *enemy)
{
    life -= 1;
    enemy->PV -= degats;
}

void Bullet::draw(sf::RenderWindow &window)
{
    anim->sprite.setPosition(location);
    window.draw(anim->sprite);
}
