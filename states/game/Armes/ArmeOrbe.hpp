#ifndef ARMEORBE_HPP
#define ARMEORBE_HPP
#include "Arme.hpp"

class ArmeOrbe : public Arme
{
    private :

        sf::Texture m_texture;
        sf::Sprite m_sprite;
        Animation m_anim;

    public :
        ArmeOrbe(Player* joueur);
        ~ArmeOrbe() {};

        void tirer(Ennemi* cible = 0);
        void upgrade();

};

#endif