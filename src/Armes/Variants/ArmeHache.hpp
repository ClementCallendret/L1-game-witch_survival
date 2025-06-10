#ifndef ARMEHACHE_HPP
#define ARMEHACHE_HPP

#include "Arme.hpp"

class ArmeHache : public Arme
{
private:
    float m_range;

public:
    ArmeHache(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeHache(){};

    void tirer();
    void upgrade();
};

#endif