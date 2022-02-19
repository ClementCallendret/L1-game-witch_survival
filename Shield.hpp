#ifndef SHIELD_HPP
#define SHIELD_HPP
#include "../Animation.hpp"
#include "../Player.h"
#include "../ennemi.h"
#include "Arme.hpp"

class Shield : public Arme
{
    private :

        sf::Texture texture;
        sf::Sprite sprite;
        Animation anim;

    public :

        ArmeBaguette(Player* joueur);
        ~ArmeBaguette() {};

        void tirer(Player* cible);
};

#endif