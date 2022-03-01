#ifndef ARMEECLAIR_HPP
#define ARMEECLAIR_HPP
#include "Arme.hpp"

class ArmeEclair : public Arme
{
    private :

        sf::Texture m_texture;
        sf::Sprite m_sprite;
        Animation m_anim;

    public :
        ArmeEclair(Player* joueur);
        ~ArmeEclair() {};

        void tirer(Ennemi* cible);
        void upgrade();
};

#endif