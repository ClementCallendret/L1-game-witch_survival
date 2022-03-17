#include "vague.hpp"

Vague::Vague(Player *p, sf::View *v) : joueur(p), vue(v)
{
    intervalle = 100;
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

void Vague::update()
{
    if (rand() % intervalle == 0)
    {
        int x, y;
        Ennemi *e;
        switch (rand() % 4)
        {
        case 0:
            x = vue->getCenter().x - 820;
            y = rand() % 900;
            e = new chevalier(joueur, sf::Vector2f(x, y));
            ensemble.push_back(e);
            break;
        case 1:
            x = vue->getCenter().x + 820;
            y = rand() % 900;
            e = new chevalier(joueur, sf::Vector2f(x, y));
            ensemble.push_back(e);
            break;
        case 2:
            x = rand() % 1600;
            y = vue->getCenter().y - 470;
            e = new chevalier(joueur, sf::Vector2f(x, y));
            ensemble.push_back(e);
            break;
        case 3:
            x = rand() % 1600;
            y = vue->getCenter().y + 470;
            e = new chevalier(joueur, sf::Vector2f(x, y));
            ensemble.push_back(e);
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
