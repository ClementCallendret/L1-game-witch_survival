#include "BulletHache.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

BulletHache::BulletHache(sf::Vector2f pos, float R, float D, float S, int Life, sf::Sprite sp, Player* j, float rng, sf::Vector2f ciblePos) : 
Bullet(pos, R, D, S, Life), sprite(sp), tireur(j), range(rng)
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
}

void BulletHache::update()
{

    if (distance < range)
    {
        location.x += speed * cos(angle); // fait avvancer le projectiles dans la bonne direction

        distance += abs(speed * sin(angle)) + abs(speed * cos(angle));
    }
    else // lorsque la hache a atteint sa range max elle revient vers le joueur
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

        location.x += speed * cos(angleRetour);
        location.y += speed * sin(angleRetour);

        distance += abs(speed * cos(angleRetour)) + abs(speed * sin(angleRetour));

        float module = sqrt(pow(Cx - location.x, 2) + pow(Cy - location.y, 2));

        if(distance > 2*range || module < 5)
            life = 0;
    }

    sprite.rotate(10); // on fait tournoyer la hache
}

void BulletHache::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletHache::draw(sf::RenderWindow &window)
{
    /* sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127));
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    window.draw(hitbox); */

    sprite.setPosition(location);
    window.draw(sprite);
}