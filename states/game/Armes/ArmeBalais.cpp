#include "ArmeBalais.hpp"
#include <sstream>

ArmeBalais::ArmeBalais(Player *joueur, std::vector<Ennemi*>* en) : 
Arme(joueur, en)
{
    m_nomArme = "Balais";
    m_icoText.loadFromFile("media/icon_broom.png");
    m_icoSprite.setTexture(m_icoText);
    m_description = {"Balais lvl 1", "+7\% de vitesse"};
    m_level = 0;
}

void ArmeBalais::upgrade()
{
    m_level++;
    std::stringstream titre ;
    titre << "Balais lvl " << m_level + 1;
    m_description[0] = titre.str();
    m_joueur->speed *= 1.07;
}