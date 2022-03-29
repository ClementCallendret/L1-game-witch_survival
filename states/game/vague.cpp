#include "vague.hpp"

Vague::Vague(Player *p, sf::View *v) : joueur(p), vue(v)
{
    intervalle = 100;
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
    case 1:
        e = new loup(joueur, pos);
        ensemble.push_back(e);
        break;
    case 2:
        e = new chauveS(joueur, pos);
        ensemble.push_back(e);
        break;
    case 3:
        e = new chevalier(joueur, pos);
        ensemble.push_back(e);
        break;
    }
}

void Vague::update()
{
    if (rand() % intervalle == 0)
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
