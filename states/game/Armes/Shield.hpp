#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Arme.hpp"

class ArmeShield : public Arme
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Animation anim;

public:
    ArmeShield(Player *joueur);
    ~ArmeShield(){};

    void tirer(Ennemi *cible = 0);
    void upgrade();
    
    void update(Ennemi *cible = 0);
    void draw(sf::RenderWindow &window);
};

#endif