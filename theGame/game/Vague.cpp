#include "Vague.hpp"
#include <random>
#include <stdio.h>

Vague::Vague(Player *p, sf::View *v) : joueur(p), vue(v)
{
    intervalle = 90;
    level = 1;
    kills = 0;
}

Vague::~Vague()
{
    for (auto i = std::begin(ensemble); ensemble.size() > 0;)
    {
        Ennemi *e = *i;
        i = ensemble.erase(i);
        delete e;
    }
}

void Vague::spawn(sf::Vector2f pos)
{
    switch (level)
    {
        Ennemi *e;
        int z;
    case 1:
        e = new villageois(joueur, pos);
        ensemble.push_back(e);
        break;
    case 2:
        z = rand() % 2;
        if (z)
            e = new chauveS(joueur, pos);
        else
            e = new villageois(joueur, pos);
        ensemble.push_back(e);
        break;
    case 3:
        z = rand() % 2;
        if (z)
            e = new chauveS(joueur, pos);
        else
            e = new chevalier(joueur, pos);
        ensemble.push_back(e);
        break;
    case 4:
        e = new villageois(joueur, pos);
        ensemble.push_back(e);
        break;
    case 5:
        e = new loup(joueur, pos);
        ensemble.push_back(e);
        break;
    case 6:
        e = new fantome(joueur, pos);
        ensemble.push_back(e);
        break;
    case 7:
        z = rand() % 2;
        if (z)
            e = new fantome(joueur, pos);
        else
            e = new gargouille(joueur, pos);
        ensemble.push_back(e);
        break;
    case 8:
        e = new gargouille(joueur, pos);
        ensemble.push_back(e);
        break;
    case 9:
        z = rand() % 2;
        if (z)
            e = new fantome(joueur, pos);
        else
            e = new arbre(joueur, pos);
        ensemble.push_back(e);
        break;
    case 10:
        e = new geant(joueur, pos);
        ensemble.push_back(e);
        break;
    case 11:
        z = rand() % 2;
        if (z)
            e = new geant(joueur, pos);
        else
            e = new loup(joueur, pos);
        ensemble.push_back(e);
        break;
    case 12:
        z = rand() % 2;
        if (z)
        {
            e = new enervax(joueur, pos);
            e->PV = 800;
        }
        else
        {
            e = new dragon(joueur, pos);
            e->PV = 1000;
        }
        ensemble.push_back(e);
        break;
    default:
        break; // YOU Win
    }
}

void Vague::update()
{
    intervalle = (90 - 7.5 * level)/2;

    if (rand() % int(intervalle) == 0)
    {
        int x, y;
        switch (rand() % 4)
        {
        case 0:
            x = vue->getCenter().x - 820;
            y = rand() % 900;
            y += vue->getCenter().y - 450;
            spawn(sf::Vector2f(x, y));
            break;
        case 1:
            x = vue->getCenter().x + 820;
            y = rand() % 900;
            y += vue->getCenter().y - 450;
            spawn(sf::Vector2f(x, y));
            break;
        case 2:
            x = rand() % 1600;
            x += vue->getCenter().x - 800;
            y = vue->getCenter().y - 470;
            spawn(sf::Vector2f(x, y));
            break;
        case 3:
            x = rand() % 1600;
            x += vue->getCenter().x - 800;
            y = vue->getCenter().y + 470;
            spawn(sf::Vector2f(x, y));
            break;
        }
    }

    for (auto i = std::begin(ensemble); i != std::end(ensemble);)
    {
        Ennemi *e = *i;
        e->update();

        if (e->PV <= 0)
        {
            i = ensemble.erase(i);
            delete e;
            kills++;
        }
        else
            i++;
    }
}

void Vague::draw(sf::RenderWindow &window)
{
    for (auto e : ensemble)
    {
        e->draw(window);
    }
}
