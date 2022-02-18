#ifndef BULLETTELEGUIDED_HPP
#define BULLETTELEGUIDED_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class BulletTeleguided : public Bullet
{
private :
    Ennemi* cible;
    Animation anim;

public :

    BulletTeleguided(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Ennemi* cible, Animation a);
    ~BulletTeleguided() {};
    
    void hit(Ennemi* enemy);

    void update();
    void draw(sf::RenderWindow &window);

};


#endif