#include "BulletHache.hpp"
#include <cmath>

BulletHache::BulletHache(sf::Vector2f pos, float R, float D, float S, int Life, Ennemi *C, sf::Sprite sp, Player* j, float rng) : 
Bullet(pos, R, D, S, Life), cible(C), sprite(sp), tireur(j), range(rng)
{

    float pente;
    float Cx = cible->getEnnemiPos().x;
    float Cy = cible->getEnnemiPos().y;

    if (location.y == Cy)
        pente = (location.x - Cx) / 0.01;
    else
        pente = (location.x - Cx) / (location.y - Cy);

    angle = atan(pente);
    if (location.y > Cy)
        angle += M_PI;
}

void BulletHache::update()
{

    if (distance < range)
    {
        location.x += speed * sin(angle); // fait avvancer le projectiles dans la bonne
        location.y += speed * cos(angle); // direction grace à la trigo

        distance += abs(speed * sin(angle)) + abs(speed * cos(angle));

        if (location.x > 1600 || location.x < 0 || location.y > 800 || location.y < 0)
            life = 0;
    }
    else
    {
        float pente;
        float Cx = tireur->getPlayerPos().x;
        float Cy = tireur->getPlayerPos().y;

        if(location.y == Cy)
            pente = (location.x - Cx) / 0.01;
        else
            pente = (location.x - Cx) / (location.y - Cy);

        float angleRetour = atan(pente);

        if (location.y > Cy)
            angleRetour += M_PI;

        location.x += speed * sin(angleRetour); // fait avvancer le projectiles dans la bonne
        location.y += speed * cos(angleRetour); // direction grace à la trigo

        distance += abs(speed * sin(angleRetour)) + abs(speed * cos(angleRetour));

        if (location.x > 1600 || location.x < 0 || location.y > 900 || location.y < 0)
            life = 0;

        float module = sqrt(pow(Cx - location.x, 2) + (Cy - location.y));

        if(distance > 2*range || module < 5)
            life = 0;
    }

    sprite.rotate(10); // on fait tourner le projectile pour qu'il pointe au bonne endroit
}

void BulletHache::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletHache::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    //window.draw(hitbox);

    // on dessine l'animation du projectile
    sprite.setPosition(location);
    window.draw(sprite);
}