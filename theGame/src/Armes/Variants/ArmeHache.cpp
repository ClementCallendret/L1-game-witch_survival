#include "ArmeHache.hpp"
#include <sstream>
#include <random>

// Bullets
#include "Variants/BulletHache.hpp"

// Core
#include "Collision.hpp"

ArmeHache::ArmeHache(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 2.5;
    m_vitesseProjectile = 5;
    m_nombreProjectile = 1;
    m_vieProjectile = 1;
    m_level = 0;
    m_nomArme = "Haches"; 
    m_cooldown = sf::seconds(3.5);
    m_clock = new sf::Clock;
    m_range = 250;

    if(!Collision::CreateTextureAndBitmask(m_texture, "media/hache.png"))
        throw "texture not loaded (hache)";

    m_sprite = new sf::Sprite(m_texture);
    m_anim = new Animation(*m_sprite, 1, sf::Vector2i(40, 55), 100, 95, 0.5, 0.2);

    m_icoText.loadFromFile("media/icon_hache.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Hache level 1", "Lance une hache tournoyante vers\n un ennemi aleatoire (elle revient)"};
}

void ArmeHache::tirer()
{
    if (!ennemis->empty())
    {
        if (m_clock->getElapsedTime() >= m_cooldown)
        {
            auto p = ennemis->begin();
            if(m_nombreProjectile < (int)ennemis->size()){
                for(int i = 0; i < rand()%((int)ennemis->size() - m_nombreProjectile) ; i++)
                    p++;
            }
            for (int i = 0; i < m_nombreProjectile && p!= ennemis->end(); i++)
            {
                Ennemi *e = *p;
                Bullet *b = new BulletHache(m_joueur->getPlayerPos(), m_degats, m_vitesseProjectile, m_vieProjectile, *m_anim, m_joueur, m_range, e->getEnnemiPos());
                m_ensemble.push_back(b);
                p++;
            }
            m_clock->restart();
        }
    }
}

void ArmeHache::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Hache level 2", "+10\% de range\n+20\% de degats"};
        break;
    case 1:
        m_level++;
        m_range *= 1.1;
        m_degats *= 1.2;
        m_description = {"Hache level 3", "+10\% de range\n+10\% de vitesse"};
        break;
    case 2:
        m_level++;
        m_range *= 1.1;
        m_vitesseProjectile *= 1.1;
        m_description = {"Hache level 4", "+25\% de taille\n+1 hache"};
        break;
    case 3:
        m_level++;
        m_sprite->scale(1.25, 1.25);
        m_nombreProjectile++;
        m_description = {"Hache level 5", "+10\% de range\n+20\% de degats"};
        break;
    case 4:
        m_level++;
        m_range *= 1.1;
        m_degats *= 1.2;
        m_description = {"Hache level 6", "+10\% de range\n+10\% de vitesse"};
        break;
    case 5:
        m_level++;
        m_range *= 1.1;
        m_vitesseProjectile *= 1.1;
        m_description = {"Hache level 7", "+10\% de range\n+20\% de degats"};
        break;
    case 6:
        m_level++;
        m_range *= 1.1;
        m_degats *= 1.2;
        m_description = {"Hache level 8", "-20\% de cooldown\n+1 hache"};
        break;
    case 7:
        m_level++;
        m_cooldown *= (float)0.8;
        m_nombreProjectile++;
        m_description = {"Hache level 9", "+10\% de degats\n"};
        break;
    default:
        m_level++;
        std::stringstream titre;
        titre << "Hache level " << m_level + 1;
        m_degats *= 1.1;
        m_description = {titre.str(), "+10\% de degats"};
        break;
    }
}