#ifndef ENNEMI_GEANT
#define ENNEMI_GEANT

#include "ennemi.h"

class geant: public Ennemi{
    public :
    geant(Player *j, sf::Vector2f loc);
    ~geant() {}

};

#endif