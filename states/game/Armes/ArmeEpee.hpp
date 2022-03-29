#ifndef ARMEEPEE_HPP
#define ARMEEPEE_HPP

#include "Arme.hpp"

class ArmeEpee : public Arme
{
public:
    float distance = 20;

    ArmeEpee(Player *joueur, std::vector<Ennemi*>* en = 0 );
    ~ArmeEpee(){};

    void tirer();
    void upgrade();
};

#endif