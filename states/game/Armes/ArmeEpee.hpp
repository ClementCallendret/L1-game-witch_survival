#ifndef ARMEEPEE_HPP
#define ARMEEPEE_HPP

#include "Arme.hpp"

class ArmeEpee : public Arme
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Animation m_animGauche;
    // Animation m_animDroite; 

public:
    ArmeEpee(Player *joueur);
    ~ArmeEpee(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif