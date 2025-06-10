#include "BulletEclair.hpp"

// Core
#include "Collision.hpp"

BulletEclair::BulletEclair(sf::Vector2f pos, float D, float S, int Life, Ennemi *C, Animation a, float scl) : 
Bullet(pos, D, S, Life, a), cible(C)
{
    location = cible->getEnnemiPos();
    anim->sprite.setPosition(location);

    Collision::CreateTextureAndBitmask(texture, "media/hitboxLight.png");

    hitbox.setTexture(texture);
    hitbox.setOrigin(19, 11.5);
    hitbox.setScale(scl, scl);
    hitbox.setPosition(location);
}

void BulletEclair::update()
{
    anim->update();
}

void BulletEclair::hit(Ennemi *enemy)
{
    enemy->PV -= degats;
}

bool BulletEclair::collision(Ennemi* enemy){
    return Collision::PixelPerfectTest(hitbox, enemy->anim.sprite);
}

void BulletEclair::draw(sf::RenderWindow &window)
{
    window.draw(anim->sprite);
    if(anim->isEnd())
        life = 0;
}