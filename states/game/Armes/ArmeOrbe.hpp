#ifndef ARMEORBE_HPP
#define ARMEORBE_HPP
#include "Arme.hpp"

class ArmeOrbe : public Arme
{
    private :

        sf::Texture texture;
        sf::Sprite sprite;
        Animation anim;

    public :
        ArmeOrbe(Player* joueur);
        ~ArmeOrbe() {};

        void tirer(Ennemi* cible = 0);
        void update(Ennemi* cible = 0);

};

#endif