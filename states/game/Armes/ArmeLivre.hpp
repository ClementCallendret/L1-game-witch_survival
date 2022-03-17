#ifndef ARMELIVRE_HPP
#define ARMELIVRE_HPP
#include "Arme.hpp"

class ArmeLivre : public Arme
{
private:
    std::vector<Arme *> *inventaire;

public:
    ArmeLivre(Player *joueur, std::vector<Arme *> *inventaire, std::vector<Ennemi*>* en = 0);
    ~ArmeLivre(){};

    void tirer() {}
    void upgrade();

    virtual void update() {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif