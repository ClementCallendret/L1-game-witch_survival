#ifndef BULLETFORBE_HPP
#define BULLETFORBE_HPP

#include "Bullet.hpp"

// Core
#include "Animation.hpp"
#include "Player.hpp"

class BulletOrbe : public Bullet
{
private:
    float angle;
    Player *tireur;
    sf::Clock dureeDeVie;

public:
    BulletOrbe(sf::Vector2f pos, float Degat, float Speed, int Life, Animation a, float ang, Player *p);
    ~BulletOrbe(){};

    void hit(Ennemi *enemy);

    void update();
};

#endif