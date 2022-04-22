#ifndef ARMEECLAIR_HPP
#define ARMEECLAIR_HPP
#include "Arme.hpp"

class ArmeEclair : public Arme
{
    private :
    float m_tailleProjectile;
public:
    ArmeEclair(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeEclair(){};

    void tirer();
    void upgrade();
}; 

#endif