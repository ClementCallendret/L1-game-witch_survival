#include "ArmeHache.hpp"
#include "BulletHache.hpp"

ArmeHache::ArmeHache(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 2;
    m_vitesseProjectile = 5;
    m_tailleProjectile = 20;
    m_nombreProjectile = 1;
    m_vieProjectile = 1;
    m_level = 0;
    m_nomArme = "Haches";
    m_cooldown = sf::seconds(3.5);
    m_clock = new sf::Clock;
    m_range = 250;

    m_texture.loadFromFile("media/hache.png");
    m_sprite = new sf::Sprite(m_texture);
    m_sprite->setOrigin(40, 55);
    m_sprite->scale(0.4, 0.4);

    m_icoText.loadFromFile("media/icon_hache.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Hache level 1", "Lance une hache tournoyante vers\nl'ennemi le plus proche (elle revient)"};
}

void ArmeHache::tirer()
{
    if (!ennemis->empty())
    {
        std::shuffle(ennemis->begin(), ennemis->end(), std::random_device());
        if (m_clock->getElapsedTime() >= m_cooldown)
        {
            Bullet *b = new BulletHache(m_joueur->getPlayerPos(), m_tailleProjectile, m_degats, m_vitesseProjectile, m_vieProjectile, *m_sprite, m_joueur, m_range, ennemis->front()->getEnnemiPos());
            m_ensemble.push_back(b);
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
        m_tailleProjectile *= 1.25;
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
        m_description = {"Hache level 9", "+10\% de dégats\n"};
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