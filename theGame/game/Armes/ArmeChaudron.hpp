#ifndef ARMECHAUDRON_HPP
#define ARMECHAUDRON_HPP
#include "Arme.hpp"

class ArmeChaudron : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeChaudron(Player *joueur, std::vector<Arme *> *inventaire, std::vector<Ennemi*>* en = 0);
    ~ArmeChaudron(){};

    void tirer() {}
    void upgrade();
    void agrandir(float n) {}

    virtual void update() {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif