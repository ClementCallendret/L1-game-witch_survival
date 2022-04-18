#include "ArmeLivre.hpp"
#include <sstream>
#include <random>

ArmeLivre::ArmeLivre(Player *joueur, std::vector<Arme *> *i, std::vector<Ennemi*>* en) : 
Arme(joueur, en), inventaire(i)
{
    m_nomArme = "Grimmoire";
    m_icoText.loadFromFile("media/icon_book.png");
    m_icoSprite.setTexture(m_icoText);
    m_description = {"Grimmoire lvl 1", "-3\% de cooldown pour toutes les\narmes actives"};
    m_level = 0;
}

void ArmeLivre::upgrade()
{
    m_level++;
    std::stringstream titre ;
    titre << "Grimmoire lvl " << m_level + 1;
    m_description[0] = titre.str();
    for(Arme* a : *inventaire)
    {
        if(a->m_level > 0)
        a->m_cooldown *= (float)0.97;
    }
}