#ifndef BULLETECLAIR_HPP
#define BULLETECLAIR_HPP

#include "Bullet.hpp"
#include "../Animation.hpp"

class BulletEclair : public Bullet
{
private:
    Ennemi *cible;
    sf::Sprite hitbox;
    sf::Texture texture;

public:
    BulletEclair(sf::Vector2f pos, float Dqaegat, float Speed, int Life, Ennemi *cible, Animation a, float r);
    ~BulletEclair(){};

    void hit(Ennemi *enemy);
    bool collision(Ennemi* enemy); 
    void draw(sf::RenderWindow &window);

    void update();
};

#endif