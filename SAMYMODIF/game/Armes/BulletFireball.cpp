#include "BulletFireball.hpp"
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

BulletFireball::BulletFireball(sf::Vector2f pos, float R, float D, float S, int Life, sf::Vector2f ciblePos, Animation a) : Bullet(pos, R, D, S, Life), anim(a)
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

    anim.sprite.setRotation(angle*180/M_PI);
}

void BulletFireball::update()
{
    location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne
    location.y += speed * sin(angle); // direction grace à la trigo
    anim.update();
    if(location.x < 0 || location.x > 1600 || location.y < 0 || location.y > 900)
    life = 0;
}

void BulletFireball::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    // window.draw(hitbox);

    // on dessine l'animation du projectile
    anim.sprite.setPosition(location);
    window.draw(anim.sprite);
}