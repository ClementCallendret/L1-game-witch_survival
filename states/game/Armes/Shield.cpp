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
}

void ArmeShield::tirer(Ennemi* cible)
{
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