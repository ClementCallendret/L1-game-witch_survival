#ifndef ARMECHAUDRON_HPP
#define ARMECHAUDRON_HPP
#include "Arme.hpp"

class ArmeChaudron : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeChaudron(Player *joueur, std::vector<Arme *> *inventaire);
    ~ArmeChaudron(){};

    void tirer(Ennemi *cible) {}
    void upgrade();

    virtual void update(Ennemi *cible) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif