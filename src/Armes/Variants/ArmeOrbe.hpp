#ifndef ARMEORBE_HPP
#define ARMEORBE_HPP

#include "Arme.hpp"

class ArmeOrbe : public Arme
{
public:
    ArmeOrbe(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeOrbe(){};

    void tirer();
    void upgrade();
};

#endif