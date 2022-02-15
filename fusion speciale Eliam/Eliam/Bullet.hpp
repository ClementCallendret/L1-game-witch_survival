#ifndef BULLET_HPP
#define BULLET_HPP
#include "Animation.hpp"
#include "Player.h"

class Enemy : public sf::Transformable
{
public:
    float x, y, rayon, life;

    sf::CircleShape sprite;

    Enemy(float X, float Y, float R, float Life);

    void draw(sf::RenderWindow &window);
};


enum ModeDeTir{teleguide, randomDir, randomPlace, rotation, boomerang};

class Bullet
{
private:
    float x, y, rayon, degats, speed, angle;
    int life;
    Animation bul_anim;
    Enemy* cible;
    ModeDeTir mdt;

    Player* tireur;

public:
    Bullet(float X, float Y, float Rayon, float Degat, float Speed, int Life, Enemy & Cible, Animation &a, ModeDeTir mDT, Player* j);

    float getBulLife();
    void hit(Enemy &enemy);
    bool collision(Enemy *a);

    void update();
    void draw(sf::RenderWindow &window);
};

#endif