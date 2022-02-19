#include "Shield.hpp"

ArmeShield::ArmeShield(Player* joueur) : Arme(joueur)
{
    degats = 0;
    vitesseProjectile = 0;
    tailleProjectile = 32;
    nombreProjectile = 1;
    vieProjectile = 50;
    level = 0;
    nomArme = "Shield";
    cooldown = sf::seconds(10);
    range = 500;

    texture.loadFromFile("media/shield.png");
    sprite.setTexture(texture);
    sprite.setOrigin(16, 16);
}

void ArmeShield::tirer(Player* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {

        ensemble.push_back(b);
        clock.restart();
    }
}