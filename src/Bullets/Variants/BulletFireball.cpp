#include "BulletFireball.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

BulletFireball::BulletFireball(sf::Vector2f pos, float D, float S, int Life, sf::Vector2f ciblePos, Animation a) : 
Bullet(pos, D, S, Life, a)
{
    // on commence par calculer l'angle vers lequel le projectile va partir (vers ciblePose)
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

    anim->sprite.setRotation(angle*180/M_PI); // on met 
}

void BulletFireball::update()
{
    location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne direction
    location.y += speed * sin(angle);
    anim->update();
    if(location.x < 0 || location.x > 3617 || location.y < 0 || location.y > 3323)
    life = 0; //faudra mettre a jour les coordonés mais ca tu le projectile quand il sort de la map
}
