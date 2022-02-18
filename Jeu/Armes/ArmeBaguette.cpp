#include "ArmeBaguette.hpp"
#include "BulletTeleguided.hpp"

ArmeBaguette::ArmeBaguette(Player* joueur) : Arme(joueur)
{
    degats = 1;
    vitesseProjectile = 5;
    tailleProjectile = 10;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Baguette Magique";
    cooldown = sf::seconds(1);

    texture.loadFromFile("media/fire_blue.png");
    sprite.setTexture(texture);

    anim = Animation(sprite, 16,  sf::Vector2i(16, 16), 32, 64);
}

void ArmeBaguette::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletTeleguided(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, cible, anim);
        ensemble.push_back(b);
        clock.restart();
    }
}