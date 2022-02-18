#ifndef ARMEBAGUETTE_HPP
#define ARMEBEGUETTE_HPP
#include "Arme.hpp"

class ArmeBaguette : public Arme
{
    private :

        sf::Texture texture;
        sf::Sprite sprite;
        Animation anim;

    public :
        ArmeBaguette(Player* joueur);
        ~ArmeBaguette() {};

        void tirer(Ennemi* cible);

};

#endif