#ifndef BULLET_HPP
#define BULLET_HPP
#include "Animation.hpp"

class Enemy : public sf::Transformable
{
public:
    float x, y, rayon, life;

    sf::CircleShape sprite;

    Enemy(float X, float Y, float R, float Life);

    void draw(sf::RenderWindow &window);
};


enum ModeDeTir{teleguide, randomm};

class Bullet
{
public:
    float x, y, rayon, life, degats, speed, angle;
    int num_frame;
    Animation bul_anim;
    Enemy *cible;
    ModeDeTir mdt;

    Bullet(float X, float Y, float R, float D, float S, Enemy & Cible, Animation &a, ModeDeTir mDT);

    void update();

    bool collision(Enemy *a);

    void draw(sf::RenderWindow &window);
};

#endif