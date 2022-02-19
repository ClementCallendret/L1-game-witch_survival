#include "BulletTeleguided.hpp"
#include <iostream>
#include <cmath>


BulletTeleguided::BulletTeleguided(sf::Vector2f pos, float R, float D, float S, int Life, Ennemi* C, Animation a) : 
Bullet(pos, R, D, S, Life), cible(C), anim(a)
{
}

void BulletTeleguided::update(){
    /* On récupère a chaque frame la position de la cible grace au pointeur cible
        puis on la vise en calculant l'angle de tir */
        float pente;
        float Cx = cible->getEnnemiPos().x;
        float Cy = cible->getEnnemiPos().y;

        if(location.x == Cx)
            pente = (location.y - Cy) / 0.01;
        else
            pente = (location.y - Cy) / (location.x - Cx);

        float angle = atan(pente);

        if (location.x > Cx)
            angle += M_PI;

        location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne
        location.y += speed * sin(angle); // direction grace à la trigo
        if (location.x > 1600 || location.x < 0 || location.y > 800 || location.y < 0)
            life = 0;

        anim.sprite.setRotation(angle * 180 / M_PI + 90); // on fait tourner le projectile pour qu'il pointe au bonne endroit
        anim.update();
}

void BulletTeleguided::hit(Ennemi* enemy)
{
    life -= 1;
    enemy->PV -= degats;
}

void BulletTeleguided::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    //window.draw(hitbox);

    // on dessine l'animation du projectile
    anim.sprite.setPosition(location);
    window.draw(anim.sprite);
}