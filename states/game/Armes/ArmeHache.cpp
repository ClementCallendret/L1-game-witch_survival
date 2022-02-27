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

    icoText.loadFromFile("media/icon_hache.png");
    icoSprite.setTexture(icoText);

    description = {"Hache level 1", "Lance une hache tournoyante vers\nl'ennemi le plus proche (elle revient)"};
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

void ArmeHache::upgrade()
{
    switch(level)
    {
        case 0:
        level++;
        description = {"Eclaire level 2", "+20\% de dégats\n+1 éclair"};
        break;
        case 1:
        level++;
        nombreProjectile++;
        degats *= 1.2;
        description = {"Eclaire level 3", "+20\% de dégats\n"};
        break;
        default:
        degats *= 1.2;
        description[0] = "Eclair level " + (level+1);
        break;
    }
}