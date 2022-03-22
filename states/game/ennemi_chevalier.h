#ifndef ENNEMI_CHEVALIER
#define ENNEMI_CHEVALIER

#include "ennemi.h"

class chevalier: public Ennemi{
    public :
    chevalier(Player *j, sf::Vector2f loc);
    ~chevalier() {}
};


#endif