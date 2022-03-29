#ifndef ENNEMI_LOUP
#define ENNEMI_LOUP

#include "ennemi.h"

class loup: public Ennemi{
    public :
    loup(Player *j, sf::Vector2f loc);
    ~loup() {}

};

#endif