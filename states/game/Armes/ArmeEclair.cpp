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

    icoText.loadFromFile("media/icon_lightning.png");
    icoSprite.setTexture(icoText);

    description = {"Eclaire level 1", "La puissance du tonerre frappe un\nennemi aleatoire."};
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

void ArmeEclair::upgrade()
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