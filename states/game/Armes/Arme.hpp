#ifndef ARME_HPP
#define ARME_HPP
#include "Bullet.hpp"
#include <string>


class Arme
{
protected:

    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int nombreProjectile, vieProjectile, level;
    std::string nomArme;

    // GESTION DU COOLDOWN
    sf::Time cooldown;
    sf::Clock clock;

    // POINTEUR VERS LE JOUEUR POUR AVOIR ACCES A SA POSITION
    Player* joueur;

    // TABLEAU DYNAMIQUE CONTENANT LES PROJECTILES
    std::vector<Bullet *> ensemble;
    
public : 

    Arme(Player* joueur);  
    virtual ~Arme();

    virtual void tirer(Ennemi* cible = 0) = 0; // purement virtuelle car chaque arme tire differement
    
    virtual void update(Ennemi* cible);
    virtual void draw(sf::RenderWindow& window);
};

#endif