#include "ArmeOrbe.hpp"
#include "BulletOrbe.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

ArmeOrbe::ArmeOrbe(Player* joueur) : Arme(joueur)
{
    degats = 2;
    vitesseProjectile = 0.03;
    tailleProjectile = 15;
    nombreProjectile = 1;
    vieProjectile = 7; // ici la vie represente la durré de vie des 
    level = 0;
    nomArme = "Orbe";
    cooldown = sf::seconds(5);

    texture.loadFromFile("media/blueorbe.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 4,  sf::Vector2i(31, 29), 64, 62, 1, 0.4);

    icoText.loadFromFile("media/icon_orbe.png");
    icoSprite.setTexture(icoText);

    description = {"Orbe level 1", "Boule d'energie qui orbite autour\ndu personnage"};
}

void ArmeOrbe::tirer(Ennemi* cible)
{
    if(!ensemble.empty()) 
        clock.restart();

    if (clock.getElapsedTime() >= cooldown)
    {
        for(int i = 0; i < nombreProjectile; i++)
        {
            float angle = i*(2*M_PI/nombreProjectile);
            Bullet *b = new BulletOrbe(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, angle, anim, joueur);
            ensemble.push_back(b);
        }
        clock.restart();
    }
}

void ArmeOrbe::upgrade()
{
    switch(level)
    {
        case 0:
        level++;
        description = {"Orbe level 2", "+20\% de dégats\n+1 orbe"};
        break;
        case 1:
        level++;
        nombreProjectile++;
        degats *= 1.2;
        description = {"Orbe level 3", "+20\% de dégats\n"};
        break;
        default:
        degats *= 1.2;
        description[0] = "Orbe level " + (level+1);
        break;
    }
}
