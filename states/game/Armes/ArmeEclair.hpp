#ifndef ARMEECLAIR_HPP
#define ARMEECLAIR_HPP
#include "Arme.hpp"

class ArmeEclair : public Arme
{
public:
    ArmeEclair(Player *joueur);
    ~ArmeEclair(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif