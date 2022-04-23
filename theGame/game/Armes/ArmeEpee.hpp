#ifndef ARMEEPEE_HPP
#define ARMEEPEE_HPP

#include "Arme.hpp"

class ArmeEpee : public Arme
{
public:
    ArmeEpee(Player *joueur, std::vector<Ennemi*>* en = 0 );
    ~ArmeEpee(){};

    void tirer();
    void upgrade();
    void agrandir(float n) {m_anim->sprite.scale(n, n/2);}
};

#endif