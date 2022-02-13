#ifndef ARME_HPP
#define ARME_HPP
#include "Animation.hpp"
#include "Bullet.hpp"
#include <string>
#include <tuple>


enum Var{degats, vitesse, nombre, taille, vie, cooldown};

class Arme
{
public:
    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int vieProjectile, nombreProjectile, level;
    std::string nomArme;
    ModeDeTir mdt;

    // ENSEMBLE DE PROJECTILE A L'ECRAN
    std::vector<Bullet *> ensemble;

    // MESURE DU TEMPS
    int compteFrame, cooldown; // pas sur encore
    
    // AMELIORATION
    std::vector<std::tuple<Var, int, std::string>> listUpgrade;

    // ANIMATION
    Animation anim;

    // il faudrait rajouter la liste des upgrades mais je ne m'en occupe pas pour l'instant
    Arme(float degats, float vitesseProjectile, int nombreProjectile, float tailleProjectile, int vieProjectile, std::string nom, int cooldown, ModeDeTir mdt, Animation &a);

    void tirer(Enemy & cible);

    void update(Enemy & cible);

    void draw(sf::RenderWindow & window);
};

#endif