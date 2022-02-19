#ifndef ARME_HPP
#define ARME_HPP
#include "Bullet.hpp"
#include "../Animation.hpp"
#include "../Player.h"
#include "../ennemi.h"
#include <string>


class Arme
{
protected:
    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int nombreProjectile, vieProjectile, level;
    std::string nomArme;

    sf::Time cooldown;
    sf::Clock clock;

    Player* joueur;

    std::vector<Bullet *> ensemble;
    
public : 

    Arme(Player* joueur);
    virtual ~Arme();

    virtual void tirer(Ennemi* cible = 0) = 0;
    // virtual void ameliorer() = 0;

    virtual void update(Ennemi* cible = 0);
    virtual void draw(sf::RenderWindow& window);
};

#endif