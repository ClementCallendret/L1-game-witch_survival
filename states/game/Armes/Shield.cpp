#include "Shield.hpp"
#include <sstream>

ArmeShield::ArmeShield(Player *joueur, std::vector<Ennemi *> *en) : Arme(joueur, en)
{
    m_degats = 0;
    m_vitesseProjectile = 0;
    m_tailleProjectile = 32;
    m_nombreProjectile = 1;
    m_vieProjectile = 50;
    m_vieMax = 50;
    m_nombreCharge = 1;
    m_level = 0;
    m_nomArme = "Shield";
    m_cooldown = sf::seconds(10);
    m_clock = new sf::Clock;

    m_texture.loadFromFile("media/shield.png");
    m_sprite = new sf::Sprite(m_texture);
    m_sprite->setOrigin(sf::Vector2f(15, 15));
    m_sprite->scale(1.75, 1.75);

    m_icoText.loadFromFile("media/icon_shield.png");
    m_icoSprite.setTexture(m_icoText);

    m_description = {"Bouclier level 1", "Un bouclier quoi  -_-  ! J'ai plus\nd'inspi."};
}

void ArmeShield::tirer()
{
    // lorsque le bouclier n'a plus de vie on lance le cooldown de recharge
    if (m_nombreCharge == m_nombreProjectile)
        m_clock->restart();
    else if (m_clock->getElapsedTime() >= m_cooldown)
    {
        m_nombreCharge++;
        m_clock->restart();
    }
}

void ArmeShield::update()
{
    // la partie avec ces deux if donne un certain nombre de frame d'invincibilité lorsque le bouclier est touché
    // m_vieProjectile = nb de frames restantes
    // m_vieMax = nb de frames totales

    if (m_vieProjectile <= 0)
    {
        m_vieProjectile = m_vieMax;
    }
    if (m_vieProjectile < m_vieMax)
    {
        m_vieProjectile--;
    }
    else
    {
        for (Ennemi *c : *ennemis)
        {
            if (collision(c))
            {
                m_vieProjectile--;
                if (m_nombreCharge > 0)
                    m_nombreCharge--;
            }
        }
    }
    tirer();
    m_sprite->setPosition(m_joueur->getPlayerPos());
    m_sprite->rotate(20);
}

bool ArmeShield::collision(Ennemi *enemy)
{
    sf::Vector2f enemyPos = enemy->getEnnemiPos();
    sf::Vector2f enemyTaille = enemy->getEnnemiTaille();
    sf::Vector2f location = m_joueur->getPlayerPos();

    float distX = abs(location.x - enemyPos.x - enemyTaille.x / 2);
    float distY = abs(location.y - enemyPos.y - enemyTaille.y / 2);

    if (distX > (enemyTaille.x / 2 + m_tailleProjectile))
    {
        return false;
    }
    if (distY > (enemyTaille.y / 2 + m_tailleProjectile))
    {
        return false;
    }

    if (distX <= (enemyTaille.x / 2))
    {
        return true;
    }
    if (distY <= (enemyTaille.y / 2))
    {
        return true;
    }

    float dx = distX - enemyTaille.x / 2;
    float dy = distY - enemyTaille.y / 2;
    return ((dx * dx + dy * dy) <= (m_tailleProjectile * m_tailleProjectile));
}

void ArmeShield::draw(sf::RenderWindow &window)
{
    if (m_nombreCharge == 1)
    {
        m_sprite->setColor(sf::Color(15, 150, 170, 100));
        window.draw(*m_sprite);
    }
    else if (m_nombreCharge == 2)
    {
        m_sprite->setColor(sf::Color(230, 200, 20, 100));
        window.draw(*m_sprite);
    }
}

void ArmeShield::upgrade()
{
    switch (m_level)
    {
    case 0:
        m_level++;
        m_description = {"Bouclier level 2", "-10\% de cooldown"};
        break;
    case 1:
        m_level++;
        m_cooldown *= (float)0.90;
        m_description = {"Bouclier level 3", "-10\% de cooldown"};
        break;
    case 2:
        m_level++;
        m_cooldown *= (float)0.90;
        m_description = {"Bouclier level 4", "+1 charge\n+100\% de temps d'invincibilité"};
        break;
    case 3:
        m_level++;
        m_nombreProjectile++;
        m_nombreCharge++;
        m_vieMax *= 2;
        m_vieProjectile = m_vieMax;
        m_description = {"Bouclier level 5", "-10\% de cooldown"};
        break;
    case 4:
        m_level++;
        m_cooldown *= (float)0.90;
        m_description = {"Bouclier level 6", "-10\% de cooldown"};
        break;
    case 5:
        m_level++;
        m_cooldown *= (float)0.90;
        m_description = {"Bouclier level 7", "-10\% de cooldown"};
        break;
    case 6:
        m_level++;
        m_cooldown *= (float)0.90;
        m_description = {"Bouclier level 8", "+100\% de temps d'invincibilité"};
        break;
    case 7:
        m_level++;
        m_nombreCharge = m_nombreProjectile;
        m_vieMax *= 2;
        m_vieProjectile = m_vieMax;
        m_description = {"Bouclier level 9", "On va s'arreter la"};
        break;
    default:
        m_level++;
        std::stringstream titre;
        titre << "Bouclier level " << m_level + 1;
        m_description = {titre.str(), "Ca fait rien du tout"};
        break;
    }
}