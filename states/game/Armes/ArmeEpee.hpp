#ifndef ARMEEPEE_HPP
#define ARMEEPEE_HPP

#include "Arme.hpp"

class ArmeEpee : public Arme
{
public:
    ArmeEpee(Player *joueur);
    ~ArmeEpee(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif