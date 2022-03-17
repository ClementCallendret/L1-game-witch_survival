#ifndef ARMEBALAIS_HPP
#define ARMEBALAIS_HPP
#include "Arme.hpp"

class ArmeBalais : public Arme
{
public:
    ArmeBalais(Player *joueur, std::vector<Ennemi*>* en = 0);
    ~ArmeBalais(){};

    void tirer() {}
    void upgrade();

    virtual void update() {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif