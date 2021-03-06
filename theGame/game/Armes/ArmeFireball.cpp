#include "ArmeFireball.hpp"
#include "../Bullets/BulletFireball.hpp"
#include "../Collision.hpp"
#include <sstream>

ArmeFireball::ArmeFireball(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 30;
    m_vitesseProjectile = 7;
    m_nombreProjectile = 1;
    m_vieProjectile = 1;
    m_level = 0;
    m_nomArme = "Fireball";
    m_cooldown = sf::seconds(2);
    m_clock = new sf::Clock;

    if(!Collision::CreateTextureAndBitmask(m_texture, "media/fireball.png"))
        throw "texture not loaded (fireball)";

    m_sprite = new sf::Sprite(m_texture);
    m_anim = new Animation(*m_sprite, 6, sf::Vector2i(35, 19), 64, 39, 0.8, 0.5);

    m_icoText.loadFromFile("media/icon_fireball.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Boule de feu level 1", "Envoie une boule de feu en direction\nd'un ennemi aleatoire."};
}

void ArmeFireball::tirer()
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
            Ennemi *e = *p;
            Bullet *b = new BulletFireball(m_joueur->getPlayerPos(), m_degats, m_vitesseProjectile, m_vieProjectile, e->getEnnemiPos(), *m_anim);
            m_ensemble.push_back(b);
            m_clock->restart();
        }
    }
}

void ArmeFireball::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Boule de feu level 2", "+20\% de degats\n-5\% de cooldown"};
        break;
    case 1:
        m_level++;
        m_cooldown *= (float)0.95;
        m_degats *= 1.2;
        m_description = {"Boule de feu level 3", "+20\% de degats\n-5\% de cooldown"};
        break;
    case 2:
        m_level++;
        m_cooldown *= (float)0.95;
        m_degats *= 1.2;
        m_description = {"Boule de feu level 4", "+30\% degats et vitesse\n+1 penetration"};
        break;
    case 3:
        m_level++;
        m_vitesseProjectile *= 1.3;
        m_degats *= 1.3;
        m_vieProjectile++;
        m_description = {"Boule de feu level 5", "+20\% de degats\n-5\% de cooldown"};
        break;
    case 4:
        m_level++;
        m_cooldown *= (float)0.95;
        m_degats *= 1.2;
        m_description = {"Boule de feu level 6", "+20\% de degats\n-5\% de cooldown"};
        break;
    case 5:
        m_level++;
        m_cooldown *= (float)0.95;
        m_degats *= 1.2;
        m_description = {"Boule de feu level 7", "+20\% de degats\n-5\% de cooldown"};
        break;
    case 6:
        m_level++;
        m_cooldown *= (float)0.95;
        m_degats *= 1.2;
        m_description = {"Boule de feu level 8", "+30\% de taille\n+1 penetration"};
        break;
    case 7:
        m_level++;
        m_vieProjectile++;
        m_anim->sprite.scale(1.3, 1.3);
        m_description = {"Boule de feu level 9", "+20\% de degats\n-5\% de cooldown"};
        break;
    default:
        m_level++;
        std::stringstream titre;
        titre << "Boule de feu level " << m_level + 1;
        m_degats *= 1.1;
        m_description = {titre.str(), "+10\% de degats"};
        break;
    }
}