#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

// Ennemis
#include "CEnnemi.hpp"

class Bullet
{
protected:
    sf::Vector2f location;
    float  degats, speed;
    int life;
    

public:
    Animation* anim;
    
    Bullet(sf::Vector2f pos, float Degat, float Speed, int Life, Animation a);
    virtual ~Bullet() { delete anim;};

    float getBulLife();
    virtual bool collision(Ennemi* enemy); // check les colisions entre un cercle et un rectangle
    virtual void hit(Ennemi* enemy);  // fait des dégats au projectile et a l'ennemi

    virtual void update() = 0;  // purement virtuel car ils ont tous un comportement different
    virtual void draw(sf::RenderWindow &window);
};

#endif