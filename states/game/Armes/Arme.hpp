#ifndef ARME_HPP
#define ARME_HPP
#include "Bullet.hpp"
#include <string>
#include <array>
#include <sstream>

class Arme
{
public : 

    // STATS
    float m_degats, m_vitesseProjectile, m_tailleProjectile;
    int m_nombreProjectile, m_vieProjectile, m_level, m_levelMax = 0;
    std::string m_nomArme;

    // GESTION DU COOLDOWN
    sf::Time m_cooldown;
    sf::Clock* m_clock = 0;

    sf::Texture m_texture;
    sf::Sprite* m_sprite = 0;
    Animation* m_anim = 0;

    // POINTEUR VERS LE JOUEUR POUR AVOIR ACCES A SA POSITION
    Player* m_joueur;

    // TABLEAU DYNAMIQUE CONTENANT LES PROJECTILES
    std::vector<Bullet *> m_ensemble;

    // icone et liste d'ameliorations
    sf::Texture m_icoText;
    sf::Sprite m_icoSprite;
    std::array<std::string, 2> m_description;


    Arme(Player* joueur);  
    virtual ~Arme();

    virtual void tirer(Ennemi* cible = 0) = 0; // purement virtuelle car chaque arme tire differement
    virtual void upgrade() = 0;
    
    virtual void update(Ennemi* cible);
    virtual void draw(sf::RenderWindow& window);
};

#endif