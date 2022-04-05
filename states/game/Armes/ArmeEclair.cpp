#include "ArmeEclair.hpp"
#include "BulletEclair.hpp"

ArmeEclair::ArmeEclair(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 3;
    m_vitesseProjectile = 2.5;
    m_tailleProjectile = 25;
    m_nombreProjectile = 1;
    m_vieProjectile = 1;
    m_level = 0;
    m_nomArme = "Lightning";
    m_cooldown = sf::seconds(3);
    m_clock = new sf::Clock;

    m_texture.loadFromFile("media/Lightning3.png");
    m_sprite = new sf::Sprite(m_texture);
    m_anim = new Animation(*m_sprite, 12, sf::Vector2i(25, 150), 50, 164, 1.5, 0.5);

    m_icoText.loadFromFile("media/icon_lightning.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Eclaire level 1", "La puissance du tonerre frappe un\nennemi aleatoire."};
}

void ArmeEclair::tirer()
{
    if (!ennemis->empty())
    {
        if (m_clock->getElapsedTime() >= m_cooldown)
        {
            std::shuffle(ennemis->begin(), ennemis->end(), std::random_device());
            auto p = ennemis->begin();
            for (int i = 0; i < m_nombreProjectile && p!= ennemis->end(); i++)
            {
                Ennemi *e = *p;
                Bullet *b = new BulletEclair(m_joueur->getPlayerPos(), m_tailleProjectile, m_degats, m_vitesseProjectile, m_vieProjectile, e, *m_anim);
                m_ensemble.push_back(b);
                m_clock->restart();
                p++;
            }
        }
    }
}

void ArmeEclair::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Eclair level 2", "+20\% de degats\n+1 eclair"};
        break;
    case 1:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Eclair level 3", "+20\% de degats\n+1 eclair"};
        break;
    case 2:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Eclaire level 4", "-0.5s de cooldown\n+2 eclair"};
        break;
    case 3:
        m_level++;
        m_nombreProjectile += 2;
        m_cooldown -= sf::seconds(0.5);
        m_description = {"Eclaire level 5", "+20\% de degats\n+1 eclair"};
        break;
    case 4:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Eclaire level 6", "+20\% de degats\n+1 eclair"};
        break;
    case 5:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Eclaire level 7", "+20\% de degats\n+1 eclair"};
        break;
    case 6:
        m_level++;
        m_nombreProjectile++;
        m_degats *= 1.2;
        m_description = {"Eclaire level 8", "-50\% de cooldown\n+50\% de taille"};
        break;
    case 7:
        m_level++;
        m_cooldown /= (float)2;
        m_tailleProjectile *= 1.5;
        m_anim->sprite.scale(1.5, 1.5);
        m_description = {"Eclaire level 9", "+10\% de degats\n+1 eclair"};
        break;
    default:
        m_level++;
        std::stringstream titre;
        titre << "Eclair level " << m_level + 1;
        m_degats *= 1.1; 
        m_description = {titre.str(), "+10\% de degats"};
        break;
    }
}