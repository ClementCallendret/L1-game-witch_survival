#ifndef ARMEBAGUETTE_HPP
#define ARMEBEGUETTE_HPP
#include "Arme.hpp"

class ArmeBaguette : public Arme
{
    public :
        ArmeBaguette(Animation* anim, Player* joueur);
        ~ArmeBaguette() {};

        void tirer(Ennemi* cible);

};

#endif