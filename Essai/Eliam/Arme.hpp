#ifndef ARME_HPP
#define ARME_HPP
#include "Animation.hpp"
#include "Bullet.hpp"
#include <string>
#include <tuple>
#include "Player.h"
#include "ennemi.h"


enum Var{degats, vitesse, nombre, taille, vie, cooldown};

class Arme
{
private:
    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int vieProjectile, nombreProjectile, level;
    std::string nomArme;
    ModeDeTir mdt;

    Player* joueur;

    // ENSEMBLE DE PROJECTILE A L'ECRAN
    std::vector<Bullet *> ensemble;

    // MESURE DU TEMPS
    sf::Time cooldown;
    sf::Clock clock;
    
    // AMELIORATION
    std::vector<std::tuple<Var, int, std::string>> listUpgrade;

    // ANIMATION
    Animation anim;
    
public : 
    // il faudrait rajouter la liste des upgrades mais je ne m'en occupe pas pour l'instant
    Arme(float degats, float vitesseProjectile, int nombreProjectile, float tailleProjectile, int vieProjectile, std::string nom, sf::Time cooldown, ModeDeTir mdt, Animation &a, Player* joueur);

    void tirer(Ennemi & cible);

    void update(Ennemi & cible);

    void draw(sf::RenderWindow & window);
};

#endif