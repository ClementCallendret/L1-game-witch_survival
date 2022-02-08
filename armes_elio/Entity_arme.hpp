#ifndef ENTITY_ARME_HPP
#define ENTITY_ARME_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <tuple>


class Enemy : public sf::Transformable
{
public:
    float x, y, rayon, life;

    Enemy(float X, float Y, float R, float Life);

    void draw(sf::RenderWindow &window);
};

class Bullet
{
public:
    float x, y, rayon, life, degats;
    int num_frame;
    sf::Texture texture;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
    Enemy *cible;

    Bullet(float X, float Y, float R, float D, Enemy & Cible, sf::Texture & t, std::vector<sf::IntRect> & f);

    void update();

    bool collision(Enemy *a);

    void draw(sf::RenderWindow &window);
};

enum Var{degats, vitesse, nombre, taille, vie, cooldown};

class Arme
{
public:
    // STATS
    float degats, vitesseProjectile, tailleProjectile;
    int vieProjectile, nombreProjectile, level;
    std::string nomArme;

    // ENSEMBLE DE PROJECTILE A L'ECRAN
    std::vector<Bullet *> ensemble;

    // MESURE DU TEMPS
    int compteFrame, cooldown; // pas sur encore
    
    // AMELIORATION
    std::vector<std::tuple<Var, int, std::string>> listUpgrade;

    // ANIMATION
    sf::Texture texture;
    std::vector<sf::IntRect> frames;

    // il faudrait rajouter la liste des upgrades mais je ne la gere pas pour l'instant
    // il faut aussi mettre la texture et les frames mais pour l'instant je les met moi meme par defaut
    Arme(float degats, float vitesseProjectile, int nombreProjectile, float tailleProjectile, int vieProjectile, std::string nom, int cooldown);

    void tirer(Enemy & cible);

    void update(Enemy & cible);
};

#endif