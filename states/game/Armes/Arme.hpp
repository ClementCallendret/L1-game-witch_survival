#ifndef ARME_HPP
#define ARME_HPP
#include "Bullet.hpp"
#include <string>
#include <array>


class Arme
{
public : 

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

    // icone et liste d'ameliorations
    sf::Texture icoText;
    sf::Sprite icoSprite;
    std::array<std::string, 2> description;


    Arme(Player* joueur);  
    virtual ~Arme();

    virtual void tirer(Ennemi* cible = 0) = 0; // purement virtuelle car chaque arme tire differement
    virtual void upgrade() = 0;
    
    virtual void update(Ennemi* cible);
    virtual void draw(sf::RenderWindow& window);
};

#endif