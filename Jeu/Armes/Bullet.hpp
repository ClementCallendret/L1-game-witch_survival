#ifndef BULLET_HPP
#define BULLET_HPP
#include "../Animation.hpp"
#include "../Player.h"
#include "../ennemi.h"



class Bullet
{
protected:
    sf::Vector2f location;
    float rayon, degats, speed;
    int life;
    Animation bul_anim;

    Player* tireur;

public:
    Bullet(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Animation* a);
    virtual ~Bullet() {};

    float getBulLife();
    virtual void hit(Ennemi* enemy);

    virtual void update() = 0;
    void draw(sf::RenderWindow &window);
};

#endif