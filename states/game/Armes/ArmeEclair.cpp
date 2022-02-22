#include "ArmeEclair.hpp"
#include "BulletEclair.hpp"

ArmeEclair::ArmeEclair(Player* joueur) : Arme(joueur)
{
    degats = 1;
    vitesseProjectile = 2.5;
    tailleProjectile = 25;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Lightning";
    cooldown = sf::seconds(2);

    texture.loadFromFile("media/Lightning3.png");
    sprite.setTexture(texture);

    anim = Animation(sprite, 12,  sf::Vector2i(25, 150), 50, 164, 1.5, 0.5);
}

void ArmeEclair::tirer(Ennemi* cible)
{
    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletEclair(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, cible, anim);
        ensemble.push_back(b);
        clock.restart();
    }
}