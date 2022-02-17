#ifndef TELEGUIDEDBULLET_HPP
#define TELEGUIDEDBULLET_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class TeleguidedBullet : public Bullet
{
private :
    Ennemi* cible;

public :

    TeleguidedBullet(sf::Vector2f pos, float Rayon, float Degat, float Speed, int Life, Animation* a, Ennemi* cible);
    ~TeleguidedBullet() {};
    
    void hit(Ennemi* enemy);

    void update();

};


#endif