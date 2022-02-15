#ifndef BULLET_HPP
#define BULLET_HPP
#include "Animation.hpp"
#include "Player.h"
#include "ennemi.h"


enum ModeDeTir{teleguide, randomDir, randomPlace, rotation, boomerang};

class Bullet
{
private:
    float x, y, rayon, degats, speed, angle;
    int life;
    Animation bul_anim;
    Ennemi* cible;
    ModeDeTir mdt;

    Player* tireur;

public:
    Bullet(float X, float Y, float Rayon, float Degat, float Speed, int Life, Ennemi & Cible, Animation &a, ModeDeTir mDT, Player* j);

    float getBulLife();
    void hit(Ennemi &enemy);
    bool collision(Ennemi *a);

    void update();
    void draw(sf::RenderWindow &window);
};

#endif