#include "ArmeEpee.hpp"
#include "../Bullets/BulletEpee.hpp"
#include "../Collision.hpp"
#include <sstream>
#include <stdio.h>

ArmeEpee::ArmeEpee(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 2;
    m_vitesseProjectile = 3;
    m_nombreProjectile = 1;
    m_vieProjectile = 7;
    m_level = 1;
    m_nomArme = "Epee";
    m_cooldown = sf::seconds(2);
    m_clock = new sf::Clock;

    if(!Collision::CreateTextureAndBitmask(m_texture, "media/animEpee.png"))
        throw "texture not loaded (epee)";


    m_sprite = new sf::Sprite(m_texture);
    m_sprite->setColor(sf::Color(255, 255, 255, 200));
    m_anim = new Animation(*m_sprite, 6, sf::Vector2i(90, 45), 150, 64, 1.7, 0.4);
    m_anim->sprite.scale(1, 0.7);

    m_icoText.loadFromFile("media/icon_epee.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Epee level 2", "+20\% de degats\n-10\% de cooldown"};
}

void ArmeEpee::tirer()
{
    if (m_clock->getElapsedTime() >= m_cooldown)
    {
        Bullet *b = new BulletEpee(m_joueur->getPlayerPos(), m_degats, m_vitesseProjectile, m_vieProjectile, *m_anim, m_joueur, m_joueur->sens);
        m_ensemble.push_back(b);
        if (m_nombreProjectile > 1)
        {
            Bullet *b2 = new BulletEpee(m_joueur->getPlayerPos(), m_degats, m_vitesseProjectile, m_vieProjectile, *m_anim, m_joueur, -(m_joueur->sens));
            m_ensemble.push_back(b2);
        }
        m_clock->restart();
    }
}

void ArmeEpee::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Epee level 2", "+20\% de degats\n-10\% de cooldown"};
        break;
    case 1:
        m_level++;
        m_degats *= 1.2;
        m_cooldown *= (float)0.9;
        m_description = {"Epee level 3", "+20\% de degats\n-10\% de cooldown"};
        break;
    case 2:
        m_level++;
        m_degats *= 1.2;
        m_cooldown *= (float)0.9;
        m_description = {"Epee level 4", "+50\% de taille\nAttaque des deux cotes"};
        break;
    case 3:
        m_level++;
        m_anim->sprite.scale(1.5, 1.15);
        m_nombreProjectile++;
        m_description = {"Epee level 5", "+20\% de degats\n-10\% de cooldown"};
        break;
    case 4:
        m_level++;
        m_degats *= 1.2;
        m_cooldown *= (float)0.9;
        m_description = {"Epee level 6", "+20\% de degats\n-10\% de cooldown"};
        break;
    case 5:
        m_level++;
        m_degats *= 1.2;
        m_cooldown *= (float)0.9;
        m_description = {"Epee level 7", "+20\% de degats\n-10\% de cooldown"};
        break;
    case 6:
        m_level++;
        m_degats *= 1.2;
        m_cooldown *= (float)0.9;
        m_description = {"Epee level 8", "+50\% de taille"};
        break;
    case 7:
        m_level++;
        m_anim->sprite.scale(1.5, 1.15);
        m_description = {"Epee level 9", "+10\% de degats"};
        break;
    default:
        m_level++;
        std::stringstream titre;
        titre << "Epee level " << m_level + 1;
        m_degats *= 1.1;
        m_description = {titre.str(), "+10\% de degats"};
        break;
    }
}