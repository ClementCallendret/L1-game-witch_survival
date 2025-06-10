#ifndef ARMECRANE_HPP
#define ARMECRANE_HPP

#include "Arme.hpp"

class ArmeCrane : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeCrane(Player *joueur, std::vector<Arme *> *inventaire, std::vector<Ennemi*>* en = 0);
    ~ArmeCrane(){};

    void tirer() {}
    void upgrade();
    void agrandir(float n) {}

    virtual void update() {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif