#ifndef ARMEHACHE_HPP
#define ARMEHACHE_HPP

#include "Arme.hpp"

class ArmeHache : public Arme
{
private:
    float m_range;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public:
    ArmeHache(Player *joueur);
    ~ArmeHache(){};

    void tirer(Ennemi *cible);
    void upgrade();
};

#endif