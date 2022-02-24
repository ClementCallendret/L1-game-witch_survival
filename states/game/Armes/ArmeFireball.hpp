#ifndef ARMEFIREBALL_HPP
#define ARMEFIREBALL_HPP
#include "Arme.hpp"

class ArmeFireball : public Arme
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    Animation anim;

public:
    ArmeFireball(Player *joueur);
    ~ArmeFireball(){};

    void tirer(Ennemi *cible);
};

#endif