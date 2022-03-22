#ifndef ENNEMI_CHAUVES
#define ENNEMI_CHAUVES

#include "ennemi.h"

class chauveS: public Ennemi{
    public :
    chauveS(Player *j, sf::Vector2f loc);
    ~chauveS() {}

};

#endif