#ifndef BULLETEPEE_HPP
#define BULLETEPEE_HPP

#include "Bullet.hpp"
#include "../Animation.hpp"
#include "../Player.hpp"

class BulletEpee : public Bullet
{
private:
    Player *tireur;
    int sens;

public:
    BulletEpee(sf::Vector2f pos, float Degat, float Speed, int Life, Animation anim, Player *joueur, int sens);
    ~BulletEpee(){};

    void hit(Ennemi *enemy);

    void update();
};

#endif