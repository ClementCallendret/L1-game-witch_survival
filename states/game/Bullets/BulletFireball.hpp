#ifndef BULLETFIREBALL_HPP
#define BULLETFIREBALL_HPP

#include "Bullet.hpp"
#include "../Animation.hpp"

class BulletFireball : public Bullet
{
private:
    Animation anim;
    float angle;

public:
    BulletFireball(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, sf::Vector2f ciblePos, Animation a);
    ~BulletFireball(){};

    void update();
    void draw(sf::RenderWindow &window);
};

#endif