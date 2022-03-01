#include "Arme.hpp"

Arme::Arme(Player *j) : m_joueur(j) 
{
    m_clock.restart();
}

Arme::~Arme()
{
    // Lorsqu'on detruit un objet Arme, on détruit chaque projectile qui lui est associé car ce sont des pointeurs
    
    for (auto i = std::begin(m_ensemble); m_ensemble.size() > 0;)
    {
        Bullet *e = *i;
        i = m_ensemble.erase(i);
        delete e;
    }
}

void Arme::update(Ennemi *cible)
{
    tirer(cible);

    for (auto i = std::begin(m_ensemble); i != std::end(m_ensemble);)
    {
        Bullet *e = *i;
        e->update(); // on fait bouger les projectiles grace a la fct update

        if (e->getBulLife() == 0) // on efface les projectiles qui sont "mort" de la mémoire
        {
            i = m_ensemble.erase(i);
            delete e;
        }
        else // on check les collisions pour les autres projectiles
        {
            if (e->collision(cible))
            {
                e->hit(cible);
            }
            i++;
        }
    }
}

void Arme::draw(sf::RenderWindow &window)
{
    for (auto b : m_ensemble) // on dessine chaque projectile de l'arme
    {
        b->draw(window);
    }
}