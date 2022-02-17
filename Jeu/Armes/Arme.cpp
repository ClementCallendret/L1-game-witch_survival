#include "Arme.hpp"
#include "../ennemi.h"
#include <cmath>
#include <iostream>
#include "TeleguidedBullet.hpp"
#define _USE_MATH_DEFINES

// oui, ca fait beaucoup mais on le fait qu'une fois par arme donc ok ca va*

Arme::Arme(Animation* an, Player* j) : anim(an), joueur(j)
{
    clock.restart();
}

Arme::~Arme() 
{
    for (auto i = std::begin(ensemble); ensemble.size() > 0;)
    {
        Bullet* e = *i;
        i = ensemble.erase(i);
        delete e;
    }
}

void Arme::update(Ennemi* cible)
{
    tirer(cible);
    // CHECKER COLLISION PEUT ETRE ICI

    for (auto i = std::begin(ensemble); i != std::end(ensemble);)
    {
        Bullet* e = *i;
        e->update(); // on fait bouger les projectiles grace a la fct update

        if (e->getBulLife() == 0) // on efface les projectiles qui sont "mort"
        {
            i = ensemble.erase(i);
            delete e;
        }
        else
            i++;
    }
}

void Arme::draw(sf::RenderWindow& window){
    for (auto b : ensemble)
        {
            b->draw(window);
        }
}