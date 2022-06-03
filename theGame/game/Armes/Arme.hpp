#ifndef ARME_HPP
#define ARME_HPP
#include "../Bullets/Bullet.hpp"
#include <string>
#include <vector>
#include <array>

class Arme
{
public : 
    // Statistiques des projectiles de l'arme
    float m_degats, m_vitesseProjectile, m_tailleProjectile;
    int m_nombreProjectile, m_vieProjectile, m_level, m_levelMax = 0;
    std::string m_nomArme;
    // Timer pour le cooldown
    sf::Time m_cooldown;
    sf::Clock* m_clock = 0;

    // Animation des projectiles
    sf::Texture m_texture;
    sf::Sprite* m_sprite = 0;
    Animation* m_anim = 0;

    // Pointeur sur le joueur
    Player* m_joueur;

    // Tableau des projectiles
    std::vector<Bullet *> m_ensemble;

    // Icone et descriptions d'améliorations
    sf::Texture m_icoText;
    sf::Sprite m_icoSprite;
    std::array<std::string, 2> m_description;
    

    // Liste des ennemis à viser
    std::vector<Ennemi*>* ennemis;


    Arme(Player* joueur, std::vector<Ennemi*>* en = 0);  
    virtual ~Arme();

    virtual void tirer() = 0; // purement virtuelle car chaque arme tire differement
    virtual void upgrade() = 0; 
    virtual void agrandir(float n) { m_anim->sprite.scale(n, n); };
    
    virtual void update();
    virtual void draw(sf::RenderWindow& window);
};

#endif