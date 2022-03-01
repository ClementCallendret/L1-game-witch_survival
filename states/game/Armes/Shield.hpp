#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Arme.hpp"

class ArmeShield : public Arme
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    int m_nombreCharge;
    int m_vieMax;

public:
    ArmeShield(Player *joueur);
    ~ArmeShield(){};

    void tirer(Ennemi *cible = 0);
    void upgrade();
    bool collision(Ennemi* ennemi);
    
    void update(Ennemi *cible = 0);
    void draw(sf::RenderWindow &window);
};

#endif