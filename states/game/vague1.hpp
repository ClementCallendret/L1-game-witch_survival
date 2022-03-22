#ifndef VAGUE1_HPP
#define VAGUE1_HPP

#include "vague.hpp"
#include "ennemi_villageois.h"

class Vague1 : public Vague
{
    Vague1(Player *j, sf::View *vue) : Vague(j, vue)
    {
        intervalle = 150;
    }
    ~Vague1(){};

    void spawn(sf::Vector2f pos)
    {
        Ennemi *e = new villageois(joueur, pos);
        ensemble.push_back(e);
    }
};

#endif
