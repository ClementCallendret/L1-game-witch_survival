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
    cooldown = sf::seconds(1);

    texture.loadFromFile("media/slashepee.png");
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 200));
    animGauche = Animation(sprite, 7,  sf::Vector2i(75, 32), 150, 64, 2, 0.4);

    icoText.loadFromFile("media/icon_epee.png");
    icoSprite.setTexture(icoText);

    description = {"Epee level 1", "Assene un coup tranchant qui oxcie\nles ennemis en face du personnage"};
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

void ArmeEpee::upgrade()
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