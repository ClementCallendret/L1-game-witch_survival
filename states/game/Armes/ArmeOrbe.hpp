#ifndef ARMEORBE_HPP
#define ARMEORBE_HPP
#include "Arme.hpp"

class ArmeOrbe : public Arme
{
public:
    ArmeOrbe(Player *joueur);
    ~ArmeOrbe(){};

    void tirer(Ennemi *cible = 0);
    void upgrade();
};

#endif