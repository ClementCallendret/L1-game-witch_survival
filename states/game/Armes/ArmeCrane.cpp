#include "ArmeCrane.hpp"
#include <sstream>

ArmeCrane::ArmeCrane(Player *joueur, std::vector<Arme *> *i, std::vector<Ennemi*>* en) : 
Arme(joueur, en), inventaire(i)
{
    m_nomArme = "Crane maudit";
    m_icoText.loadFromFile("media/icon_skull.png");
    m_icoSprite.setTexture(m_icoText);
    m_description = {"Crane maudit lvl 1", "+10\% de degats pour toutes les\narmes actives"};
    m_level = 0;
}

void ArmeCrane::upgrade()
{
    m_level++;
    std::stringstream titre ;
    titre << "Crane maudit lvl " << m_level + 1;
    m_description[0] = titre.str();
    for(Arme* a : *inventaire)
    {
        if(a->m_level > 0)
        a->m_cooldown *= (float)0.97;
    }
    if(m_level > 3) m_levelMax = 1;
}