#include "Arme.hpp"
#include "../Collision.hpp"

Arme::Arme(Player *j, std::vector<Ennemi *> *en) : m_joueur(j), ennemis(en)
{
}

Arme::~Arme()
{
    // On supprime tous les ennemis, l'animation si il y en a une
    for (auto i = std::begin(m_ensemble); m_ensemble.size() > 0;)
    {
        Bullet *e = *i;
        i = m_ensemble.erase(i);
        delete e;
    }
    if (m_clock)
        delete m_clock;
    if (m_sprite)
        delete m_sprite;
    if (m_anim)
        delete m_anim;
}

void Arme::update()
{
    tirer();

    for (auto i = std::begin(m_ensemble); i != std::end(m_ensemble);)
    {
        Bullet *e = *i;
        e->update(); // on fait bouger chaque projectile grace a sa fct update

        if (e->getBulLife() <= 0) // on efface les projectiles qui sont "mort" de la mémoire
        {
            i = m_ensemble.erase(i);
            delete e;
        }
        else // on check les collisions pour les autres projectiles
        {
            if (!ennemis->empty())
            {
                for (Ennemi *c : *ennemis)
                {
                    if (e->collision(c))
                    {
                        e->hit(c);
                    }
                }
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