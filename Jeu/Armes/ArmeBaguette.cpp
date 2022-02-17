#include "ArmeBaguette.hpp"
#include "TeleguidedBullet.hpp"

ArmeBaguette::ArmeBaguette(Animation* anim, Player* joueur) : Arme(anim, joueur)
{
    degats = 1;
    vitesseProjectile = 5;
    tailleProjectile = 10;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 1;
    nomArme = "Baguette Magique";
    cooldown = sf::seconds(1);
}

void ArmeBaguette::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new TeleguidedBullet(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, anim, cible);
        ensemble.push_back(b);
        clock.restart();
    }
}