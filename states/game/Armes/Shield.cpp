#include "Shield.hpp"

ArmeShield::ArmeShield(Player* joueur) : Arme(joueur)
{
    degats = 0;
    vitesseProjectile = 0;
    tailleProjectile = 32;
    nombreProjectile = 1;
    vieProjectile = 50;
    level = 0;
    nomArme = "Shield";
    cooldown = sf::seconds(10);

    texture.loadFromFile("media/shield.png");
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 100));
    anim = Animation(sprite, 4, sf::Vector2i(16, 16), 32, 32, 2);

    icoText.loadFromFile("media/icon_hache.png");
    icoSprite.setTexture(icoText);

    description = {"Bouclier level 1", "Un bouclier quoi  -_-  ! J'ai plus\nd'inspi."};
}

void ArmeShield::tirer(Ennemi* cible)
{
    // lorsque le bouclier n'a plus de vie on lance le cooldown de recharge
    if (vieProjectile > 0) clock.restart();
    else if (clock.getElapsedTime() >= cooldown)
    {
        vieProjectile = 50;
        clock.restart();
    }
}

void ArmeShield::update(Ennemi* cible)
{
    anim.update();
    anim.sprite.setPosition(joueur->getPlayerPos());
}

void ArmeShield::draw(sf::RenderWindow &window)
{
    if(vieProjectile > 0) window.draw(anim.sprite);
}

void ArmeShield::upgrade()
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