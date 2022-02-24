#include "ArmeOrbe.hpp"
#include "BulletOrbe.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

ArmeOrbe::ArmeOrbe(Player* joueur) : Arme(joueur)
{
    degats = 2;
    vitesseProjectile = 0.03;
    tailleProjectile = 15;
    nombreProjectile = 4;
    vieProjectile = 7; // ici la vie represente la durré de vie des 
    level = 0;
    nomArme = "Orbe";
    cooldown = sf::seconds(5);

    texture.loadFromFile("media/blueorbe.png");
    sprite.setTexture(texture);

    anim = Animation(sprite, 4,  sf::Vector2i(31, 29), 64, 62, 1, 0.4);
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
