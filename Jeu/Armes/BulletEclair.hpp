#ifndef BULLETECLAIR_HPP
#define BULLETECLAIR_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class BulletEclair : public Bullet
{
private :
    Ennemi* cible;
    Animation anim;

public :

    BulletEclair(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Ennemi* cible, Animation a);
    ~BulletEclair() {};
    
    void hit(Ennemi* enemy);

    void update();
    void draw(sf::RenderWindow &window);

};


#endif