#ifndef ARMEFIREBALL_HPP
#define ARMEFIREBALL_HPP
#include "Arme.hpp"

class ArmeFireball : public Arme
{
public:
    ArmeFireball(Player *joueur);
    ~ArmeFireball(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif