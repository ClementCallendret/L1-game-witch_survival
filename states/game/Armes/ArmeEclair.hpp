#ifndef ARMEECLAIR_HPP
#define ARMEECLAIR_HPP
#include "Arme.hpp"

class ArmeEclair : public Arme
{
    private :

        sf::Texture texture;
        sf::Sprite sprite;
        Animation anim;

    public :
        ArmeEclair(Player* joueur);
        ~ArmeEclair() {};

        void tirer(Ennemi* cible);
        void upgrade();
};

#endif