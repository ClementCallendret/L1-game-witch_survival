#ifndef ARMEBALAIS_HPP
#define ARMEBALAIS_HPP
#include "Arme.hpp"

class ArmeBalais : public Arme
{
public:
    ArmeBalais(Player *joueur);
    ~ArmeBalais(){};

    void tirer(Ennemi *cible) {}
    void upgrade();

    virtual void update(Ennemi *cible) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif