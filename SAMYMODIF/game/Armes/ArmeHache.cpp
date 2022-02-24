#include "ArmeHache.hpp"
#include "BulletHache.hpp"

ArmeHache::ArmeHache(Player* joueur) : Arme(joueur)
{
    degats = 2;
    vitesseProjectile = 3;
    tailleProjectile = 20;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Haches";
    cooldown = sf::seconds(3.5);
    range = 500;

    texture.loadFromFile("media/hache.png");
    sprite.setTexture(texture);
    sprite.setOrigin(40, 55);
    sprite.scale(0.4, 0.4);
}

void ArmeHache::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletHache(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, sprite, joueur, range, cible->getEnnemiPos());
        ensemble.push_back(b);
        clock.restart();
    }
}