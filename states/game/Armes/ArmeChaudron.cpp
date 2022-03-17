#include "ArmeChaudron.hpp"

ArmeChaudron::ArmeChaudron(Player *joueur, std::vector<Arme *> *i, std::vector<Ennemi*>* en) : Arme(joueur, en), inventaire(i)
{
    m_nomArme = "Potion verte";
    m_icoText.loadFromFile("media/icon_cauldron.png");
    m_icoSprite.setTexture(m_icoText);
    m_description = {"Potion verte lvl 1", "+10\% de taille pour toutes les\narmes actives"};
    m_level = 0;
}

void ArmeChaudron::upgrade()
{
    m_level++;
    std::stringstream titre;
    titre << "Potion verte lvl " << m_level + 1;
    m_description[0] = titre.str();
    for (Arme *a : *inventaire)
    {
        if (a->m_level > 0 && a->m_nomArme != "Shield")
        {
            a->m_tailleProjectile *= 1.1;
            if(a->m_anim)
            a->m_anim->sprite.scale(1.1, 1.1);
            else if(a->m_sprite)
            a->m_sprite->scale(1.1, 1.1);
        }
    }
    if (m_level > 5)
        m_levelMax = 1;
}