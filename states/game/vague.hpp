#ifndef VAGUE_HPP
#define VAGUE_HPP
#include "ennemi.h"
#include "ennemi_villageois.h"
#include "ennemi_chevalier.h"
#include <vector>

class Vague {
public:
    Player *joueur;
    sf::View *vue;
    int intervalle;
    std::vector<Ennemi *> ensemble;


    Vague(Player *j, sf::View* vue);
    virtual ~Vague();

    virtual void update();
    virtual void draw(sf::RenderWindow &window);

};


#endif