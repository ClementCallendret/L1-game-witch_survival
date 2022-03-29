#ifndef ENNEMI_ENERVAX
#define ENNEMI_ENERVAX

#include "ennemi.h"

class enervax: public Ennemi{
    public :
    enervax(Player *j, sf::Vector2f loc);
    ~enervax() {}

};

#endif