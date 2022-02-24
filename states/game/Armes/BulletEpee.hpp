#ifndef BULLETEPEE_HPP
#define BULLETEPEE_HPP

#include "Bullet.hpp"

class BulletEpee : public Bullet
{
private:
    Animation *anim;
    Player *tireur;

public:
    BulletEpee(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Animation *anim, Player *joueur);
    ~BulletEpee(){};

    void hit(Ennemi *enemy);

    void update();
    void draw(sf::RenderWindow &window);
};

#endif