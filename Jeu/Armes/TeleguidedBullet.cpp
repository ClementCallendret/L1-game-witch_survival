#include "TeleguidedBullet.hpp"
#include <iostream>
#include <cmath>


TeleguidedBullet::TeleguidedBullet(sf::Vector2f pos, float R, float D, float S, int Life, Animation* a, Ennemi* C) : 
Bullet(pos, R, D, S, Life, a), cible(C)
{
}

void TeleguidedBullet::update(){
    /* On récupère a chaque frame la position de la cible grace au pointeur cible
        puis on la vise en calculant l'angle de tir */
        float pente;
        float Cx = cible->getEnnemiPos().x;
        float Cy = cible->getEnnemiPos().y;

        if(location.y == Cy)
            pente = (location.x - Cx) / 0.0001;
        else
            pente = (location.x - Cx) / (location.y - Cy);

        float angle = atan(pente);

        if (location.y > Cy)
            angle += M_PI;

        location.x += speed * sin(angle); // fait avvancer le projectiles dans la bonne
        location.y += speed * cos(angle); // direction grace à la trigo
        if (location.x > 1600 || location.x < 0 || location.y > 800 || location.y < 0)
            life = 0;

        bul_anim.sprite.setRotation(-1 * angle * 180 / M_PI + 180); // on fait tourner le projectile pour qu'il pointe au bonne endroit
        bul_anim.update();
}

void TeleguidedBullet::hit(Ennemi* enemy)
{
    life -= 1;
    enemy->PV -= degats;
}