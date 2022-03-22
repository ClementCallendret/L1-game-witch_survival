#ifndef ENNEMI_VILLAGEOIS
#define ENNEMI_VILLAGEOIS


#include "ennemi.h"

class villageois: public Ennemi{
    public :
    villageois(Player *j, sf::Vector2f loc);
    ~villageois() {}


};


#endif