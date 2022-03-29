#ifndef ENNEMI_ARBRE
#define ENNEMI_ARBRE

#include "ennemi.h"

class arbre: public Ennemi{
    public :
    arbre(Player *j, sf::Vector2f loc);
    ~arbre() {}

};

#endif