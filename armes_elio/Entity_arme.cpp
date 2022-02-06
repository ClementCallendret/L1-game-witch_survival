#include "Entity_arme.hpp"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES


Enemy::Enemy(float X, float Y, float R, float Life) : x(X), y(Y), rayon(R), life(Life)
{
}

void Enemy::draw(sf::RenderWindow &window)
{
    sf::CircleShape enemySprite(rayon);
    enemySprite.setFillColor(sf::Color::Red);
    enemySprite.setOrigin(sf::Vector2f(rayon, rayon));
    enemySprite.setPosition(sf::Vector2f(x, y));
    window.draw(enemySprite);
}


Bullet::Bullet(float X, float Y, float R, float D, Enemy & Cible) : x(X), y(Y), rayon(R), degats(D), cible(&Cible)
{
    life = 1; // donner de la vie au projectile pourrait lui permettre de toucher plusieurs ennemis

    texture.loadFromFile("fire_blue.png");

    for (int i=0;i<16;i++)
        frames.push_back(sf::IntRect(i*32, 0, 32, 64));  // tableau contenant chaque frame de l'animation
    
    bul_sprite.setTexture(texture);
    bul_sprite.setOrigin(sf::Vector2f(16, 32));  
    num_anim_bullet = 0;
}

void Bullet::update()
{
    /* On récupère a chaque frame la position de la cible grace au pointeur cible
        puis on la vise en calculant l'angle de tir */

    float pente = (x - cible->x) / (y - cible->y);
    float angle = atan(pente);

    if (y > cible->y)
        angle += M_PI;

    x += 0.1 * (180 / M_PI) * sin(angle); // fait avvancer le projectiles dans la bonne
    y += 0.1 * (180 / M_PI) * cos(angle); // direction grace à la trigo
    if (x > 1200 || x < 0 || y > 800 || y < 0)
        life = 0;

    bul_sprite.setRotation(-1*angle*180/M_PI+180);  // on fait tourner le projectile pour qu'il pointe au bonne endroit
    num_anim_bullet = (num_anim_bullet+1)%16;
}

bool Bullet::collision(Enemy *a)
{
    return (x - a->x) * (x - a->x) +
            (y - a->y) * (y - a->y) <
           (a->rayon + rayon) * (a->rayon + rayon); // J'ai pas encore compris le calcul mais ca detecte bien les collisions
}

void Bullet::draw(sf::RenderWindow &window)
{
    /* sf::CircleShape bulletSprite(rayon);
    bulletSprite.setFillColor(sf::Color(255, 0, 0, 127));  // ce cercle nous permet de voir la hitbox
    bulletSprite.setOrigin(sf::Vector2f(rayon, rayon));
    bulletSprite.setPosition(sf::Vector2f(x, y));
    window.draw(bulletSprite); */

    // on dessine l'animation du projectile
    bul_sprite.setTextureRect(frames[num_anim_bullet]);
    bul_sprite.setPosition(x, y);
    window.draw(bul_sprite);
}