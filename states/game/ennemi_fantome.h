#ifndef ENNEMI_FANTOME
#define ENNEMI_FANTOME

#include "ennemi.h"

class fantome: public Ennemi{
    public :
    fantome(Player *j, sf::Vector2f loc);
    ~fantome() {}

};

#endif