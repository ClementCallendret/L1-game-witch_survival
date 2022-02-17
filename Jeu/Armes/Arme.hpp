#ifndef ARME_HPP
#define ARME_HPP
#include "../Animation.hpp"
#include "Bullet.hpp"
#include <string>
#include "../Player.h"
#include "../ennemi.h"


class Arme
{
protected:
    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int nombreProjectile, vieProjectile, level;
    std::string nomArme;

    sf::Time cooldown;
    sf::Clock clock;

    Animation* anim;

    Player* joueur;

    std::vector<Bullet *> ensemble;
    
public : 

    Arme(Animation* anim, Player* joueur);
    virtual ~Arme();

    virtual void tirer(Ennemi* cible) = 0;
    // virtual void ameliorer() = 0;

    void update(Ennemi* cible);
    void draw(sf::RenderWindow& window);
};

#endif