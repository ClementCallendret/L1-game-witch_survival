#ifndef ARMEFIREBALL_HPP
#define ARMEFIREBALL_HPP
#include "Arme.hpp"

class ArmeFireball : public Arme
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    Animation m_anim;

public:
    ArmeFireball(Player *joueur);
    ~ArmeFireball(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif