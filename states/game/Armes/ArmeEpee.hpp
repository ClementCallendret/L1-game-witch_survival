#ifndef ARMEEPEE_HPP
#define ARMEEPEE_HPP

#include "Arme.hpp"

class ArmeEpee : public Arme
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Animation animGauche;
    // Animation animDroite; 

public:
    ArmeEpee(Player *joueur);
    ~ArmeEpee(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif