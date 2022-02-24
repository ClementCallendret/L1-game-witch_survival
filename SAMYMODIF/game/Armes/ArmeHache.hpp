#ifndef ARMEHACHE_HPP
#define ARMEHACHE_HPP

#include "Arme.hpp"

class ArmeHache : public Arme
{
    private :

        float range;
        sf::Texture texture;
        sf::Sprite sprite;

    public :
        ArmeHache(Player* joueur);
        ~ArmeHache() {};

        void tirer(Ennemi* cible);

};

#endif