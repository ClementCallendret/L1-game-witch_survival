#ifndef ENNEMI_DRAGON
#define ENNEMI_DRAGON

#include "ennemi.h"

class dragon: public Ennemi{
    public :
    dragon(Player *j, sf::Vector2f loc);
    ~dragon() {}

};

#endif