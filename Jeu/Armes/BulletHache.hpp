#ifndef BULLETHACHE_HPP
#define BULLETHACHE_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class BulletHache : public Bullet
{
private :
    Ennemi* cible;
    sf::Sprite sprite;
    Player* tireur;
    float range, angle;
    float distance = 0;

public :

    BulletHache(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Ennemi* cible, sf::Sprite sprite, Player* j, float range);
    ~BulletHache() {};
    
    void hit(Ennemi* enemy);

    void update();
    void draw(sf::RenderWindow &window);

};


#endif