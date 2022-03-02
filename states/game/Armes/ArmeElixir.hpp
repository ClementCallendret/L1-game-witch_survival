#ifndef ARMEELIXIR_HPP
#define ARMEELIXIR_HPP
#include "Arme.hpp"

class ArmeElixir : public Arme
{
public:
    ArmeElixir(Player *joueur);
    ~ArmeElixir(){};

    void tirer(Ennemi *cible) {}
    void upgrade();

    virtual void update(Ennemi *cible);
    virtual void draw(sf::RenderWindow &window) {}
};

#endif