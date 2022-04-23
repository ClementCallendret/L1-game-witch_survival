#ifndef ENNEMI_DRAGON
#define ENNEMI_DRAGON

#include "CEnnemi.hpp"

class dragon : public Ennemi
{
public:
    dragon(Player *j, sf::Vector2f loc) : Ennemi(j, loc)
    {
        speed = 1;
        PV = 10000;
        degat = 3;
        xp = 50;
        name = "Dragon";
        ratio = 1;
        if (!Collision::CreateTextureAndBitmask(texture, "media/dragon.png"))
            throw "texture not loaded (dragon)";
        sprite.setTexture(texture);
        anim = Animation(sprite, 11, sf::Vector2i(70, 100), 220, 220, 1, 0.2);
        taille = sf::Vector2f(180, 200);
    }
    ~dragon() {}
};

#endif