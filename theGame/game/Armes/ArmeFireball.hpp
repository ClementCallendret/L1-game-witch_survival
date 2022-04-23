#ifndef ARMEFIREBALL_HPP
#define ARMEFIREBALL_HPP
#include "Arme.hpp"

class ArmeFireball : public Arme
{
public:
    ArmeFireball(Player *joueur, std::vector<Ennemi*>* en = 0 );
    ~ArmeFireball(){};

    void tirer();
    void upgrade();
};

#endif