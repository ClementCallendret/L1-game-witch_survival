#include "ArmeFireball.hpp"
#include "BulletFireball.hpp"

ArmeFireball::ArmeFireball(Player* joueur) : Arme(joueur)
{
    degats = 2;
    vitesseProjectile = 0.05;
    tailleProjectile = 15;
    nombreProjectile = 1;
    vieProjectile = 5;
    level = 0;
    nomArme = "FireBall";
    cooldown = sf::seconds(3);

    texture.loadFromFile("media/fireball.png");
    sprite.setTexture(texture);

    anim = Animation(sprite, 6,  sf::Vector2i(315, 150), 500, 300, 0.15, 0.5);
}

void ArmeFireball::tirer(Ennemi* cible)
{
    if(!ensemble.empty()) clock.restart();

    if (clock.getElapsedTime() >= cooldown)
    {
        Bullet *b = new BulletFireball(joueur->getPlayerPos(), tailleProjectile, degats, vitesseProjectile, vieProjectile, -90, anim, joueur);
        ensemble.push_back(b);
        clock.restart();
    }
}

void ArmeFireball::update(Ennemi* cible)
{
    tirer();
    // CHECKER COLLISION PEUT ETRE ICI

    for (auto i = std::begin(ensemble); i != std::end(ensemble);)
    {
        Bullet* e = *i;
        e->update(); // on fait bouger les projectiles grace a la fct update

        if (e->getBulLife() == 0) // on efface les projectiles qui sont "mort"
        {
            i = ensemble.erase(i);
            delete e;
        }
        else
            i++;
    }
}