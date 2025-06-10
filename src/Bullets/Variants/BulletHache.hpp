#ifndef BULLETHACHE_HPP
#define BULLETHACHE_HPP

#include "Bullet.hpp"

// Core
#include "Player.hpp"

class BulletHache : public Bullet
{
private:
    Player *tireur;
    float range, angle;
    float distance = 0;

public:
    BulletHache(sf::Vector2f pos, float Degat, float Speed, int Life, Animation a, Player *j, float range, sf::Vector2f ciblePos);
    ~BulletHache(){};

    void hit(Ennemi *enemy);

    void update();
};

#endif