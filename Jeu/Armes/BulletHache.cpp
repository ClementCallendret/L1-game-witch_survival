#include "BulletHache.hpp"
#include <cmath>

BulletHache::BulletHache(sf::Vector2f pos, float R, float D, float S, int Life, Ennemi *C, sf::Sprite sp, Player* j, float rng) : 
Bullet(pos, R, D, S, Life), cible(C), sprite(sp), tireur(j), range(rng)
{

    float pente;
    float Cx = cible->getEnnemiPos().x;
    float Cy = cible->getEnnemiPos().y;

    if (location.x == Cx)
        pente = (location.y - Cy) / 0.01;
    else
        pente = (location.y - Cy) / (location.x - Cx);

    angle = atan(pente);
    if (location.x > Cx)
        angle += M_PI;
}

void BulletHache::update()
{

    if (distance < range)
    {
        location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne
        location.y += speed * sin(angle); // direction grace à la trigo

        distance += abs(speed * sin(angle)) + abs(speed * cos(angle));

        if (location.x > 1600 || location.x < 0 || location.y > 800 || location.y < 0)
            life = 0;
    }
    else
    {
        float pente;
        float Cx = tireur->getPlayerPos().x;
        float Cy = tireur->getPlayerPos().y;

        if(location.x == Cx)
            pente = (location.y - Cy) / 0.01;
        else
            pente = (location.y - Cy) / (location.x - Cx);

        float angleRetour = atan(pente);

        if (location.x > Cx)
            angleRetour += M_PI;

        location.x += speed * cos(angleRetour); // fait avvancer le projectiles dans la bonne
        location.y += speed * sin(angleRetour); // direction grace à la trigo

        distance += abs(speed * cos(angleRetour)) + abs(speed * sin(angleRetour));

        if (location.x > 1600 || location.x < 0 || location.y > 900 || location.y < 0)
            life = 0;

        float module = sqrt(pow(Cx - location.x, 2) + pow(Cy - location.y, 2));

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
    // window.draw(hitbox);

    // on dessine l'animation du projectile
    sprite.setPosition(location);
    window.draw(sprite);
}