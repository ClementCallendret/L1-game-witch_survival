#ifndef BULLETFIREBALL_HPP
#define BULLETFIREBALL_HPP

#include "Bullet.hpp"

// Core
#include "Animation.hpp"

class BulletFireball : public Bullet
{
private:
    float angle;

public:
    BulletFireball(sf::Vector2f pos, float Degat, float Speed, int Life, sf::Vector2f ciblePos, Animation a);
    ~BulletFireball(){};

    void update();
};

#endif