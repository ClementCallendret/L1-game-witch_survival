#ifndef BULLETFIREBALL_HPP
#define BULLETFIREBALL_HPP

#include "Bullet.hpp"

class BulletFireball : public Bullet
{
private :
    float angle;
    Animation anim;
    Player* tireur;
    sf::Clock dureeDeVie;

public :

    BulletFireball(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, float ang, Animation a, Player* p);
    ~BulletFireball() {};
    
    void hit(Ennemi* enemy);

    void update();
    void draw(sf::RenderWindow &window);

};

#endif