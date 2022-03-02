#ifndef ARMELIVRE_HPP
#define ARMELIVRE_HPP
#include "Arme.hpp"

class ArmeLivre : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeLivre(Player *joueur, std::vector<Arme *> *inventaire);
    ~ArmeLivre(){};

    void tirer(Ennemi *cible) {}
    void upgrade();

    virtual void update(Ennemi *cible) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif