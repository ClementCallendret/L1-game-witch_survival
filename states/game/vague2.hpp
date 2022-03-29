#ifndef VAGUE1_HPP
#define VAGUE1_HPP

#include "vague.hpp"
#include "ennemi_chevalier.h"
#include "ennemi_geant.h"


class Vague2 : public Vague
{
public:
    Vague2(Player *j, sf::View *vue) : Vague(j, vue)
    {
        intervalle = 100;
    }
    ~Vague2(){};

    void spawn(sf::Vector2f pos)
    {
        Ennemi *e = new chevalier(joueur, pos); //remplacer gant par chevalier
        ensemble.push_back(e);
    }
};

#endif
