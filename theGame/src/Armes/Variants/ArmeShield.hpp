#ifndef SHIELD_HPP
#define SHIELD_HPP

// Arme
#include "Arme.hpp"

// Core
#include "Player.hpp"

class ArmeShield : public Arme
{
public:
    ArmeShield(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeShield(){};

    void tirer();
    void upgrade();
    void agrandir(float n) {}
    bool collide(Ennemi* ennemi);
    
    void update();
    void draw(sf::RenderWindow &window);

    int m_nombreCharge;
    int m_vieMax;
};

#endif