#include "BulletEpee.hpp"

BulletEpee::BulletEpee(sf::Vector2f pos, float R, float D, float S, int Life, Animation* a, Player* j) : 
Bullet(pos, R, D, S, Life), anim(a), tireur(j)
{
}

void BulletEpee::update()
{
    location = tireur->getPlayerPos();
    anim->update();
}

void BulletEpee::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

void BulletEpee::draw(sf::RenderWindow &window)
{
    sf::CircleShape hitbox(rayon);
    hitbox.setFillColor(sf::Color(255, 0, 0, 127)); // ce cercle nous permet de voir la hitbox
    hitbox.setOrigin(sf::Vector2f(rayon, rayon));
    hitbox.setPosition(location);
    // window.draw(hitbox);

    // on dessine l'animation du projectile
    anim->sprite.setPosition(location);
    window.draw(anim->sprite);
    if(anim->num_frame > anim->nbtot_frames - 1) { life = 0; anim->num_frame = 0;}
    
}