#include "Bullet.hpp"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

Bullet::Bullet(float X, float Y, float R, float D, float S, Enemy &Cible, Animation &a, ModeDeTir mDT) : x(X), y(Y), rayon(R), degats(D), speed(S), cible(&Cible), bul_anim(a), mdt(mDT)
{
    life = 1; // donner de la vie au projectile pourrait lui permettre de toucher plusieurs ennemis

    if (mdt == 1)
    {
        angle = rand() % 360;
        bul_anim.sprite.setRotation(-1 * angle * 180 / M_PI + 180);
    }
}

void Bullet::update()
{
    // Le comportement des bullet est definit en fonction du mode de tire
    
    switch (mdt)
    {
    case teleguide:
    {
        /* On récupère a chaque frame la position de la cible grace au pointeur cible
        puis on la vise en calculant l'angle de tir */

        float pente = (x - cible->x) / (y - cible->y);
        angle = atan(pente);

        if (y > cible->y)
            angle += M_PI;

        x += speed * (180 / M_PI) * sin(angle); // fait avvancer le projectiles dans la bonne
        y += speed * (180 / M_PI) * cos(angle); // direction grace à la trigo
        if (x > 1200 || x < 0 || y > 800 || y < 0)
            life = 0;

        bul_anim.sprite.setRotation(-1 * angle * 180 / M_PI + 180); // on fait tourner le projectile pour qu'il pointe au bonne endroit
        bul_anim.update();
    }
    break;

    case randomm:
    {
        // ici un angle aleatoire est definit des le départ et la balle va tout droit

        x += speed * (180 / M_PI) * sin(angle); // fait avvancer le projectiles dans la bonne
        y += speed * (180 / M_PI) * cos(angle); // direction grace à la trigo
        if (x > 1200 || x < 0 || y > 800 || y < 0)
            life = 0;

        bul_anim.update();
    }

    break;
    }
}

bool Bullet::collision(Enemy *a)
{
    return (x - a->x)*(x - a->x)+
         (y - a->y)*(y - a->y)<
         (a->rayon + rayon)*(a->rayon + rayon);
}

void Bullet::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(sf::Vector2f(x, y));
    window.draw(hitbox);

    // on dessine l'animation du projectile
    bul_anim.sprite.setPosition(x, y);
    window.draw(bul_anim.sprite);
}

Enemy::Enemy(float X, float Y, float R, float Life) : x(X), y(Y), rayon(R), life(Life)
{
    sprite.setRadius(rayon);
}

void Enemy::draw(sf::RenderWindow &window)
{
    sprite.setFillColor(sf::Color::Red);
    sprite.setOrigin(sf::Vector2f(rayon, rayon));
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}