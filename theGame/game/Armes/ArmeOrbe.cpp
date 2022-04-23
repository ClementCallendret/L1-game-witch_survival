#include "ArmeOrbe.hpp"
#include "../Bullets/BulletOrbe.hpp"
#include "../Collision.hpp"
#include <sstream>
#include <cmath>
#define _USE_MATH_DEFINES

ArmeOrbe::ArmeOrbe(Player *joueur, std::vector<Ennemi*>* en) : Arme(joueur, en)
{
    m_degats = 1.5;
    m_vitesseProjectile = 0.03;
    m_nombreProjectile = 1;
    m_vieProjectile = 7; // ici la vie represente la durré de vie des
    m_level = 0;
    m_nomArme = "Orbe";
    m_cooldown = sf::seconds(5);
    m_clock = new sf::Clock;

    if(!Collision::CreateTextureAndBitmask(m_texture, "media/blueorbe.png"))
        throw "texture not loaded (orbe)";
        
    m_sprite = new sf::Sprite(m_texture);
    m_anim = new Animation(*m_sprite, 4, sf::Vector2i(31, 29), 64, 62, 1, 0.4);

    m_icoText.loadFromFile("media/icon_orbe.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Orbe level 1", "Boule d'energie qui orbite autour\ndu personnage"};
}

void ArmeOrbe::tirer()
{
    if (!m_ensemble.empty())
        m_clock->restart();

    if (m_clock->getElapsedTime() >= m_cooldown)
    {
        for (int i = 0; i < m_nombreProjectile; i++)
        {
            float angle = i * (2 * M_PI / m_nombreProjectile);
            Bullet *b = new BulletOrbe(m_joueur->getPlayerPos(), m_degats, m_vitesseProjectile, m_vieProjectile, *m_anim, angle, m_joueur);
            m_ensemble.push_back(b);
        }
        m_clock->restart();
    }
}

void ArmeOrbe::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Orbe level 2", "+20\% de degats\n+1 orbe"};
        break;
    case 1:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Orbe level 3", "+20\% de degats\n+1 orbe"};
        break;
    case 2:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Orbe level 4", "+20\% de vitesse\n+30\% de taille"};
        break;
    case 3:
        m_level++;
        m_anim->sprite.scale(1.3, 1.3);
        m_vitesseProjectile *= 1.2;
        m_description = {"Orbe level 5", "+20\% de degats\n+1 orbe"};
        break;
    case 4:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Orbe level 6", "+20\% de degats\n+1 orbe"};
        break;
    case 5:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Orbe level 7", "+20\% de degats\n+1 orbe"};
        break;
    case 6:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Orbe level 8", "+25\% de vitesse\nPlus aucun cooldown"};
        break;
    case 7:
        m_level++;
        m_vitesseProjectile *= 1.25;
        m_cooldown = sf::seconds(0.1);
        m_description = {"Orbe level 9", "+10\% de degats"};
        break;
    default:
        m_level++;
        std::stringstream titre ;
        titre << "Orbe level " << m_level + 1;
        m_degats *= 1.1;
        m_description = {titre.str(), "+10\% de degats"};
        break;
        
    }
}
