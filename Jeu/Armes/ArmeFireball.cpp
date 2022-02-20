#include "ArmeFireball.hpp"
#include "BulletFireball.hpp"

ArmeFireball::ArmeFireball(Player* joueur) : Arme(joueur)
{
    degats = 1;
    vitesseProjectile = 4;
    tailleProjectile = 10;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Baguette Magique";
    cooldown = sf::seconds(1);

    texture.loadFromFile("media/fireball2.png");
    sprite.setTexture(texture);

    anim = Animation(sprite, 6,  sf::Vector2i(45, 19), 64, 39, 0.8, 0.5);
}

void ArmeFireball::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletFireball(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, cible->getEnnemiPos(), anim);
        ensemble.push_back(b);
        clock.restart();
    }
}