#include "ArmeFireball.hpp"
#include "BulletFireball.hpp"

ArmeFireball::ArmeFireball(Player* joueur) : Arme(joueur)
{
    degats = 1;
    vitesseProjectile = 2.5;
    tailleProjectile = 10;
    nombreProjectile = 1;
    vieProjectile = 1;
    level = 0;
    nomArme = "Fireball";
    cooldown = sf::seconds(2);

    texture.loadFromFile("media/fireball2.png");
    sprite.setTexture(texture);
    anim = Animation(sprite, 6,  sf::Vector2i(45, 19), 64, 39, 0.8, 0.5);

    icoText.loadFromFile("media/icon_fireball.png");
    icoSprite.setTexture(icoText);

    description = {"Boule de feu level 1", "Envoie une boule de feu en direction\nd'un ennemi aleatoire."};
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

void ArmeFireball::upgrade()
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