#include "ArmeElixir.hpp"

ArmeElixir::ArmeElixir(Player *joueur) : 
Arme(joueur)
{
    m_nomArme = "Elixir de vie";
    m_icoText.loadFromFile("media/icon_elixir.png");
    m_icoSprite.setTexture(m_icoText);
    m_description = {"Elixir de vie lvl 1", "+10\% d'hp max\nSoigne +0.5\% d'hp par seconde"};
    m_level = 0;
    m_cooldown = sf::seconds(1);
    m_clock = new sf::Clock;
}

void ArmeElixir::update(Ennemi *cible)
{
    if(m_clock->getElapsedTime() >= m_cooldown)
    {
        m_joueur->heal(m_level*0.05*m_joueur->pvMax);
    }
}

void ArmeElixir::upgrade()
{
    m_level++;
    std::stringstream titre ;
    titre << "Elixir de vie lvl " << m_level + 1;
    m_description[0] = titre.str();
    m_joueur->pvMax *= 1.1;
}