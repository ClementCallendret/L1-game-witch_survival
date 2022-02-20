#include "ArmeEpee.hpp"
#include "BulletEpee.hpp"

ArmeEpee::ArmeEpee(Player* joueur) : Arme(joueur)
{
    degats = 2;
    vitesseProjectile = 3;
    tailleProjectile = 20;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Epee";
    cooldown = sf::seconds(1.5);

    texture.loadFromFile("media/slashepee.png");
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 200));
    animGauche = Animation(sprite, 7,  sf::Vector2i(75, 32), 150, 64, 2, 0.4);
}

void ArmeEpee::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletEpee(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, &animGauche, joueur);
        ensemble.push_back(b);
        clock.restart();
    }
}