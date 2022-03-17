#ifndef ARMEELIXIR_HPP
#define ARMEELIXIR_HPP
#include "Arme.hpp"

class ArmeElixir : public Arme
{
public:
    ArmeElixir(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeElixir(){};

    void tirer() {}
    void upgrade();

    virtual void update();
    virtual void draw(sf::RenderWindow &window) {}
};

#endif