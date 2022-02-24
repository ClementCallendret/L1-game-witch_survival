#ifndef BULLETFORBE_HPP
#define BULLETFORBE_HPP

#include "Bullet.hpp"

class BulletOrbe : public Bullet
{
private:
    float angle;
    Animation anim;
    Player *tireur;
    sf::Clock dureeDeVie;

public:
    BulletOrbe(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, float ang, Animation a, Player *p);
    ~BulletOrbe(){};

    void hit(Ennemi *enemy);

    void update();
    void draw(sf::RenderWindow &window);
};

#endif