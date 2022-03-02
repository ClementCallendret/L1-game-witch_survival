#ifndef ARMECRANE_HPP
#define ARMECRANE_HPP
#include "Arme.hpp"

class ArmeCrane : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeCrane(Player *joueur, std::vector<Arme *> *inventaire);
    ~ArmeCrane(){};

    void tirer(Ennemi *cible) {}
    void upgrade();

    virtual void update(Ennemi *cible) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif