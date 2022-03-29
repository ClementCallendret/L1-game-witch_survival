#ifndef VAGUE1_HPP
#define VAGUE1_HPP

#include "vague.hpp"
#include "ennemi_villageois.h"
#include "ennemi_geant.h" //a supprimer

class Vague1 : public Vague
{
    Vague1(Player *j, sf::View *vue) : Vague(j, vue)
    {
        intervalle = 150;
    }
    ~Vague1(){};

    void spawn(sf::Vector2f pos)
    {
        Ennemi *e = new geant(joueur, pos); //remettre villageois a la place de géant
        ensemble.push_back(e);
    }
};

#endif
