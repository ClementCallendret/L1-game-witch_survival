#ifndef ENNEMI_GARGOUILLE
#define ENNEMI_GARGOUILLE

#include "ennemi.h"

class gargouille: public Ennemi{
    public :
    gargouille(Player *j, sf::Vector2f loc);
    ~gargouille() {}

};

#endif